reg_t addr = RS1 + insn.s_imm();
printf("srdlg 0x%lx pc=%lx\n", addr, pc);
srs_t *srs;
srs = p->get_mmu()->get_srs();
srs->delegate(addr);
