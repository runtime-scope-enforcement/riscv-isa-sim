reg_t limit = RS1 + insn.s_imm();
printf("srlmt 0x%lx pc=%lx\n", limit, pc);
srs_t *srs;
srs = p->get_mmu()->get_srs();
srs->limit(limit);
