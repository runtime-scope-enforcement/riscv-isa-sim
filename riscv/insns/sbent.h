validate_csr(CSR_CYCLE, false);
printf("sbent pc=%lx\n", pc);
srs_t *srs;
srs = p->get_mmu()->get_srs();
if (!srs->is_on(p->get_state()->prv)) {
  srs->turn_on(p->get_state()->prv);
}
srs->switch_ctx(p->get_state()->minstret, pc, SBENT);
srs->enter();
