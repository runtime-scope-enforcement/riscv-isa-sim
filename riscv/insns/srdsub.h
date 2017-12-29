reg_t base = RS1;
reg_t limit = RS2 + insn.s_imm();
printf("srdsub 0x%lx 0x%lx pc=%lx\n", base, limit, pc);
srs_t *srs;
srs = p->get_mmu()->get_srs();
srs->delegate_sub(base, limit);
//srs->sub(base, limit);
//srs->delegate_move(base);
