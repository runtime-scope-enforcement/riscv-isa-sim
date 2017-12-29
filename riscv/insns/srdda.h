reg_t base = RS1 + insn.s_imm();
reg_t limit = RS2;
printf("srdda 0x%lx 0x%lx pc=%lx\n", base, limit, pc);
srs_t *srs;
srs = p->get_mmu()->get_srs();
srs->dda(base, limit);
