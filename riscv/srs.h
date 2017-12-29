#ifndef _RISCV_SRS_H
#define _RISCV_SRS_H

#include "decode.h"
#include "processor.h"
#include <vector>

#define SRS_STACK_FRAMES 11
#define SRS_ENTRIES 122

enum {XSCEN_ACCESS_LOAD, XSCEN_ACCESS_STORE};
enum {XSCEN_MODE_STRICT, XSCEN_MODE_LAX, XSCEN_MODE_DEBUG};
enum {
  SBENT,
  SRADD,
  SRDDA,
  SRDLG,
  SRDSUB,
  SBXIT
};

static unsigned int cycle_counts[] {1,1,1,2,2,2};

struct srs_entry {
  reg_t base;
  reg_t limit;
};

struct srs_frame {
  unsigned int count;
  struct srs_entry *entries;
};

struct srs_bank {
  unsigned int active;
  struct srs_entry entries[SRS_ENTRIES];
};

struct ctx_switch_stat {
  int instruction;
  unsigned int bankA;
  unsigned int bankB;
  reg_t cycles;
};

class srs_t {
private:
  struct srs_bank bank_a;
  struct srs_bank bank_b;
  struct srs_frame stack[SRS_STACK_FRAMES];
  unsigned int stack_size;
  reg_t last_ctx_switch;
  bool on;
  reg_t mode;
  unsigned enforcing_mode;

  unsigned int inst_count[7];
  unsigned int context_switches;
  unsigned int fast_context_switches;
  unsigned int access_check_cntr;

  std::vector<ctx_switch_stat> ctx_switch_stats;

  struct srs_entry *find_free(reg_t addr);
  struct srs_entry *find_entry(reg_t addr);
  void bank_swap();
  void push();
  void pop();

public:
  srs_t();
  bool is_on(reg_t priv);
  void turn_off();
  void turn_on(reg_t priv);
  bool access_check(reg_t addr, size_t len, reg_t pc);
  void enter();
  void exit();
  void base(reg_t addr);
  void limit(reg_t addr);
  void add(reg_t base, reg_t limit);
  void dda(reg_t base, reg_t limit);
  void delegate(reg_t addr);
  void delegate_move(reg_t addr);
  void sub(reg_t base, reg_t limit);
  void delegate_sub(reg_t base, reg_t limit);
  void switch_ctx(reg_t cycle, reg_t pc, int instruction);
  void print_state();
  void violation(reg_t addr, size_t len, unsigned access, processor_t *proc);
  void set_enforcing_mode(unsigned mode);
  unsigned int get_inst_count(int instr);
  unsigned int get_cycle_count(int instr);
  unsigned int total_instructions();
  unsigned int total_cycles();
  unsigned int get_context_switches();
  unsigned int get_fast_context_switches();
  unsigned int get_access_check_cntr();
  unsigned int get_enforcing_mode();
  void print_stats(processor_t *proc);
};

#endif
