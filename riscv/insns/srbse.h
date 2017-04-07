reg_t base = RS1 + insn.s_imm();
printf("srbse 0x%lx pc=%lx\n", base, pc);
srs_t *srs;
srs = p->get_mmu()->get_srs();
srs->base(base);
