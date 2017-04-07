#include "srs.h"
#include "processor.h"
#include "trap.h"
#include <stdio.h>
#include <stdlib.h>

#define SRS_ASSERT(x, m) if(!(x)){printf("SRS_ASSERT FAILED: " m "\n");print_state();abort();}

srs_t::srs_t() :
  stack_size(0), last_ctx_switch(0), on(false), mode(-1), inst_count{0},
  context_switches(0), fast_context_switches(0), access_check_cntr(0) {
  bank_a = {0, {(struct srs_entry){0, 0}}};
  bank_b = {0, {(struct srs_entry){0, 0}}};
}


bool srs_t::is_on(reg_t priv) {
  //printf("is_on: %s && %lu == %lu = %s\n", on?"true":"false", priv, mode, on && (priv == mode) ? "on":"off");
  return on && (priv == mode);
}

void srs_t::turn_on(reg_t priv) {
  mode = priv;
  on = true;
}

void srs_t::turn_off() {
  on = false;
}

void srs_t::push() {
  SRS_ASSERT(stack_size < SRS_STACK_FRAMES, "SRS stack overflow")
  unsigned int n = bank_a.active;
  struct srs_frame *frame = &stack[stack_size];
  frame->count = n;
  frame->entries = new struct srs_entry[n];

  for (unsigned int i = 0; i < n; i++) {
    struct srs_entry e;
    e = bank_a.entries[i];
    frame->entries[i] = e;
  }

  stack_size++;
  printf("STACK: %d\n", stack_size);
}

void srs_t::pop() {
  SRS_ASSERT(stack_size > 0, "SRS stack is empty");
  struct srs_frame *frame = &stack[stack_size-1];
  unsigned int popn = frame->count;
  unsigned int dlgn = bank_b.active;
  SRS_ASSERT(popn+dlgn < SRS_ENTRIES, "Saved SRS frame wont fit to registers");

  for (unsigned int i = 0; i < popn; i++) {
    struct srs_entry e;
    e = frame->entries[i];
    bank_b.entries[i+dlgn] = e;
  }

  bank_b.active = popn+dlgn;
  stack_size--;
}

void srs_t::bank_swap() {
  struct srs_bank tmp;
  tmp = bank_a;
  bank_a = bank_b;
  bank_b = tmp;
  bank_b.active = 0;
}

void srs_t::enter() {
  inst_count[SBENT]++;
  push();
  bank_a.active = 0;
  bank_swap();
}

void srs_t::exit() {
  inst_count[SBXIT]++;
  pop();
  bank_swap();
  if (stack_size == 0) {
    bank_a.active = 0;
    on = false;
  }
}

void srs_t::base(reg_t addr) {
  SRS_ASSERT(bank_a.active < SRS_ENTRIES, "SRBSE: bank A is full");
  inst_count[SRBSE]++;
  unsigned int i = bank_a.active;
  bank_a.entries[i].base = addr;
}

void srs_t::limit(reg_t addr) {
  SRS_ASSERT(bank_a.active < SRS_ENTRIES, "SRLMT: bank A is full");
  inst_count[SRLMT]++;
  unsigned int i = bank_a.active;
  bank_a.entries[i].limit = addr;
  SRS_ASSERT(bank_a.entries[i].base <= addr, "limit can't be less than base");
  bank_a.active++;
  printf("BANKA: %d\n", bank_a.active);
}

void srs_t::delegate(reg_t addr) {
  inst_count[SRDLG]++;
  SRS_ASSERT(bank_a.active > 0, "no active entries in bank A");
  SRS_ASSERT(bank_b.active < SRS_ENTRIES, "bank B is already full");
  if (addr == 0) return;
  struct srs_entry *e = find_entry(addr);
  if (!e && this->enforcing_mode >= XSCEN_MODE_LAX) {
    printf("DELEGATE: ignore lookup miss in lax mode\n");
    return;
  }
  SRS_ASSERT(e != NULL, "can't find a matching entry from bank A");
  unsigned int i = bank_b.active;
  bank_b.entries[i].base = e->base;
  bank_b.entries[i].limit = e->limit;
  bank_b.active++;
  printf("BANKB: %d\n", bank_b.active);
}

void srs_t::delegate_move(reg_t addr) {
  inst_count[SRDLGM]++;
  SRS_ASSERT(bank_a.active > 0, "no active entries in bank A");
  SRS_ASSERT(bank_b.active < SRS_ENTRIES, "bank B is already full");

  struct srs_entry *e = find_entry(addr);
  if (!e && this->enforcing_mode >= XSCEN_MODE_LAX) {
    printf("DELEGATE: ignore lookup miss in lax mode\n");
    return;
  }
  SRS_ASSERT(e != NULL, "can't find a matching entry from bank A");
  SRS_ASSERT(e == &bank_a.entries[bank_a.active-1], "match found, but it's not on the top of the frame");
  unsigned int i = bank_b.active;
  bank_b.entries[i].base = e->base;
  bank_b.entries[i].limit = e->limit;
  bank_b.active++;
  bank_a.active--;
  printf("BANKA: %d\n", bank_a.active);
  printf("BANKB: %d\n", bank_b.active);
}

void srs_t::sub(reg_t base, reg_t limit) {
  SRS_ASSERT(limit >= base, "SRSUB: limit must be greater than or equal to base");
  inst_count[SRSUB]++;
  reg_t regsize = limit-base+1;
  bool ok = access_check(base, regsize, 0);
  SRS_ASSERT(ok, "SRSUB: sub region is not in bounds of any rule");

  SRS_ASSERT(bank_a.active <= SRS_ENTRIES, "SRSUB: bank A is full");
  unsigned int i = bank_a.active;
  bank_a.entries[i].base = base;
  bank_a.entries[i].limit = limit;
  bank_a.active++;
  printf("BANKA: %d\n", bank_a.active);
}

bool srs_t::access_check(reg_t addr, size_t len, reg_t pc) {
  if (this->enforcing_mode == XSCEN_MODE_DEBUG) {
    printf("  CHECKING ACCESS: addr=%lx len=%lu pc=%lx\n", addr, len, pc);
    this->print_state();
  }
  if (!on) return true;
  access_check_cntr++;

  if (bank_a.active == 0) return false;
  for (int i = bank_a.active-1; i >= 0; i--) {
    struct srs_entry e;
    e = bank_a.entries[i];
    if (addr+len-1 <= e.limit &&
        addr       >= e.base) return true;
  }
  return false;
}

void srs_t::violation(reg_t addr, size_t len, unsigned access, processor_t *proc) {
  const char *msg;
  switch (access) {
    case XSCEN_ACCESS_LOAD:
      msg = "load";
      break;
    case XSCEN_ACCESS_STORE:
      msg = "store";
      break;
    default:
      SRS_ASSERT(0, "unknown access");
  }

  this->print_state();
  printf("scope violation when %s 0x%08lx, len=%lu, pc=%lx\n", msg, addr, len, proc->get_state()->pc);
  switch (this->enforcing_mode) {
    case XSCEN_MODE_LAX:
    case XSCEN_MODE_STRICT:
      printf("strict mode\n");
      abort();
      break;
    case XSCEN_MODE_DEBUG:
      printf("debug mode\n");
      this->turn_off();
      break;
    default:
      SRS_ASSERT(0, "unknown enforcing mode");
  }
  switch (access) {
    case XSCEN_ACCESS_LOAD:
      throw trap_load_access_fault(addr);
      break;
    case XSCEN_ACCESS_STORE:
      throw trap_store_access_fault(addr);
      break;
    default:
      SRS_ASSERT(0, "unknown access");
  }
}

void srs_t::set_enforcing_mode(unsigned enforcing_mode) {
  this->enforcing_mode = enforcing_mode;
}

struct srs_entry *srs_t::find_entry(reg_t addr) {
  if (bank_a.active == 0) return NULL;
  for (int i = bank_a.active-1; i >= 0; i--) {
    struct srs_entry e;
    e = bank_a.entries[i];
    if (e.base <= addr && e.limit >= addr) {
      return &bank_a.entries[i];
    }
  }
  return NULL;
}

void srs_t::switch_ctx(reg_t cycle, reg_t pc, int instruction) {
  ctx_switch_stats.push_back((struct ctx_switch_stat){instruction, bank_a.active, bank_b.active, cycle});
  if (last_ctx_switch && cycle < last_ctx_switch+SRS_ENTRIES) {
    fast_context_switches++;
  }

  context_switches++;
  last_ctx_switch = cycle;
}

void srs_t::print_state() {
  printf("   SRS STATE:   frames in stack: %d\n", stack_size);
  printf("   %10s %-30u    %10s %-30u\n", "BANK A", bank_a.active, "BANK B", bank_b.active);
  printf("   %-18s %-18s    %-18s %-18s\n", "base", "limit", "base", "limit");
  for (unsigned int i = 0; i < bank_a.active || i < bank_b.active; i++) {
    printf("%3s", "");
    if (i < bank_a.active) {
      struct srs_entry e;
      e = bank_a.entries[i];
      printf("0x%016lx 0x%016lx", e.base, e.limit);
    } else {
      printf("%-18s %-18s", "", "");
    }
    printf("%4s", "");
    if (i < bank_b.active) {
      struct srs_entry e;
      e = bank_b.entries[i];
      printf("0x%016lx 0x%016lx", e.base, e.limit);
    }
    printf("\n");
  }
  printf("\n");

  if (stack_size) {
    printf("   topmost frame in stack\n");
    printf("   %-18s %-18s\n", "base", "limit");

    struct srs_frame *topmost = &stack[stack_size-1];
    for (unsigned int i = 0; i < topmost->count; i++) {
      printf("%3s", "");
      struct srs_entry e;
      e = topmost->entries[i];
      printf("0x%016lx 0x%016lx", e.base, e.limit);
      printf("\n");
    }
  }
  printf("\n");
}

void srs_t::print_stats(processor_t *proc) {
  fflush(stdout);
  fprintf(stderr, "Cycles reported by CPU: %lu\n", proc->get_state()->minstret);
  fprintf(stderr, "Xscen instructions: %u\n", total_instructions());
  fprintf(stderr, "  %s: %5u %5u\n", "sbent ", get_inst_count(SBENT), get_cycle_count(SBENT));
  fprintf(stderr, "  %s: %5u %5u\n", "srbse ", get_inst_count(SRBSE), get_cycle_count(SRBSE));
  fprintf(stderr, "  %s: %5u %5u\n", "srlmt ", get_inst_count(SRLMT), get_cycle_count(SRLMT));
  fprintf(stderr, "  %s: %5u %5u\n", "srdlg ", get_inst_count(SRDLG), get_cycle_count(SRDLG));
  fprintf(stderr, "  %s: %5u %5u\n", "srdlgm", get_inst_count(SRDLGM), get_cycle_count(SRDLGM));
  fprintf(stderr, "  %s: %5u %5u\n", "sbxit ", get_inst_count(SBXIT), get_cycle_count(SBXIT));
  fprintf(stderr, "  %s: %5u %5u\n", "srsub ", get_inst_count(SRSUB), get_cycle_count(SRSUB));
  fprintf(stderr, "Xscen context switches: %u\n", get_context_switches());
  fprintf(stderr, "Xscen fast context switches: %u\n", get_fast_context_switches());
  fprintf(stderr, "Access checks: %u\n", get_access_check_cntr());

  if (ctx_switch_stats.empty()) return;
  unsigned int i = 0, fast = 0;
  double sumdiff = 0;
  double sumbanka = 0;
  double sumbankb = 0;
  reg_t lastcycles = 0;
  unsigned int cshist[SRS_ENTRIES] = {0};
  unsigned int cshist_a[SRS_ENTRIES] = {0};
  unsigned int cshist_b[SRS_ENTRIES] = {0};
  unsigned int cshist_move[SRS_ENTRIES] = {0};
  unsigned int cshist_movefast[SRS_ENTRIES] = {0};
  unsigned int cshist_stacktot[SRS_ENTRIES*10] = {0};
  lastcycles = ctx_switch_stats[0].cycles;
  unsigned int to_move = 0;
  unsigned int tot_stack = 0;
  unsigned int big_stack = 0;
  unsigned int tot_stall = 0;
  unsigned int add_cycles = 0;
  std::vector<unsigned int> stackn;

  for (i=1; i < ctx_switch_stats.size(); i++) {
    //cycles between two context switches
    unsigned int diff = ctx_switch_stats[i].cycles-lastcycles-1;
    unsigned int banka = ctx_switch_stats[i].bankA;
    unsigned int bankb = ctx_switch_stats[i].bankB;

    to_move = 0;
    if (ctx_switch_stats[i].instruction == SBENT) {
      if (!stackn.empty())
        to_move = stackn.back();
    } else {
      if (stackn.size() > 1)
        to_move = *(stackn.end()-2);
    }

    cshist_move[to_move]++;
    if (ctx_switch_stats[i].instruction == SBXIT) {
      cshist_stacktot[tot_stack]++;
    }
    if (diff < SRS_ENTRIES) {
      fast++;
      cshist[diff]++;
      cshist_a[banka]++;
      cshist_b[bankb]++;
      sumdiff += diff;
      sumbanka += banka;
      sumbankb += bankb;

      if (diff < to_move) {
        cshist_movefast[to_move-diff]++;
        tot_stall += to_move-diff;
      }
    }
    lastcycles = ctx_switch_stats[i].cycles;

    //keep track of stack
    if (ctx_switch_stats[i].instruction == SBENT) {
      tot_stack += banka;
      stackn.push_back(banka);
    } else if (!stackn.empty()) {
      tot_stack -= stackn.back();
      stackn.pop_back();
    }
    big_stack = big_stack > tot_stack ? big_stack : tot_stack;
  }

  add_cycles = tot_stall;
  add_cycles += total_cycles();

  fprintf(stderr, "fast ctx switch (total %d/%d) distribution, cycles:\n", fast, i);
  fprintf(stderr, "columns:\n");
  fprintf(stderr, "       ctx switch cycle diff\n");
  fprintf(stderr, "              bank a size\n");
  fprintf(stderr, "                     bank b size\n");
  fprintf(stderr, "                            entries to move to/from cache\n");
  fprintf(stderr, "                                   move count - cycles\n");
  fprintf(stderr, "                                          total stack size on exit\n");
  for (int i = 0; i < (int) big_stack || i < SRS_ENTRIES; i++) {
    fprintf(stderr, "  %3d:", i);
    if (i<SRS_ENTRIES) {
      fprintf(stderr, " %-6d", cshist[i]);
      fprintf(stderr, " %-6d", cshist_a[i]);
      fprintf(stderr, " %-6d", cshist_b[i]);
      fprintf(stderr, " %-6d", cshist_move[i]);
      fprintf(stderr, " %-6d", cshist_movefast[i]);
    }
    fprintf(stderr, " %-6d\n", cshist_stacktot[i]);
  }

  fprintf(stderr, "total cycles reported without xscen cycles: %-6lu\n", proc->get_state()->minstret-total_instructions());
  fprintf(stderr, "total stalling due to fast ctx switches: %-6d\n", tot_stall);
  fprintf(stderr, "total extra cycles from Xscen instructions: %-6d\n", add_cycles);
  fprintf(stderr, "total approximated cycles: %-6lu\n", proc->get_state()->minstret-total_instructions()+add_cycles);
}

unsigned int srs_t::get_cycle_count(int instr) {
  return inst_count[instr]*cycle_counts[instr];
}

unsigned int srs_t::total_cycles() {
  int total = 0;
  total += get_cycle_count(SBENT);
  total += get_cycle_count(SRBSE);
  total += get_cycle_count(SRLMT);
  total += get_cycle_count(SRDLG);
  total += get_cycle_count(SRDLGM);
  total += get_cycle_count(SBXIT);
  total += get_cycle_count(SRSUB);
  return total;
}

unsigned int srs_t::get_inst_count(int instr) {
  return inst_count[instr];
}

unsigned int srs_t::total_instructions() {
  int total = 0;
  for (auto it : inst_count) {
    total += it;
  }
  return total;
}

unsigned int srs_t::get_context_switches() {
  return context_switches;
}

unsigned int srs_t::get_fast_context_switches() {
  return fast_context_switches;
}

unsigned int srs_t::get_access_check_cntr() {
  return access_check_cntr;
}

unsigned int srs_t::get_enforcing_mode() {
  return enforcing_mode;
}
