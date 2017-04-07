validate_csr(CSR_CYCLE, false);
printf("sbxit pc=%lx\n", pc);
srs_t *srs;
srs = p->get_mmu()->get_srs();
srs->switch_ctx(p->get_state()->minstret, pc, SBXIT);
srs->exit();
