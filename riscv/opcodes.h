DECLARE_INSN(movn, 0x6f7, 0x1ffff)
DECLARE_INSN(vfsstw, 0x150f, 0x1ffff)
DECLARE_INSN(remuw, 0x7bb, 0x1ffff)
DECLARE_INSN(fmin_d, 0x180d3, 0x1ffff)
DECLARE_INSN(vlsthu, 0x128b, 0x1ffff)
DECLARE_INSN(c_swsp, 0x8, 0x1f)
DECLARE_INSN(bltu, 0x363, 0x3ff)
DECLARE_INSN(vlsegstwu, 0xb0b, 0xfff)
DECLARE_INSN(vvcfg, 0x473, 0xf801ffff)
DECLARE_INSN(movz, 0x2f7, 0x1ffff)
DECLARE_INSN(fcvt_lu_s, 0x9053, 0x3ff1ff)
DECLARE_INSN(c_ld, 0x9, 0x1f)
DECLARE_INSN(c_srli32, 0xc19, 0x1c1f)
DECLARE_INSN(fmin_s, 0x18053, 0x1ffff)
DECLARE_INSN(c_lw0, 0x12, 0x801f)
DECLARE_INSN(slliw, 0x9b, 0x3f83ff)
DECLARE_INSN(lb, 0x3, 0x3ff)
DECLARE_INSN(vlwu, 0x30b, 0x3fffff)
DECLARE_INSN(fcvt_s_wu, 0xf053, 0x3ff1ff)
DECLARE_INSN(fcvt_d_l, 0xc0d3, 0x3ff1ff)
DECLARE_INSN(lh, 0x83, 0x3ff)
DECLARE_INSN(fcvt_d_w, 0xe0d3, 0x3ff1ff)
DECLARE_INSN(lw, 0x103, 0x3ff)
DECLARE_INSN(add, 0x33, 0x1ffff)
DECLARE_INSN(fcvt_d_s, 0x100d3, 0x3ff1ff)
DECLARE_INSN(mfpcr, 0x17b, 0x3fffff)
DECLARE_INSN(c_fsd, 0x18, 0x1f)
DECLARE_INSN(fmax_d, 0x190d3, 0x1ffff)
DECLARE_INSN(bne, 0xe3, 0x3ff)
DECLARE_INSN(rdcycle, 0x277, 0x7ffffff)
DECLARE_INSN(fcvt_s_d, 0x11053, 0x3ff1ff)
DECLARE_INSN(vlh, 0x8b, 0x3fffff)
DECLARE_INSN(bgeu, 0x3e3, 0x3ff)
DECLARE_INSN(vflstd, 0x158b, 0x1ffff)
DECLARE_INSN(c_li, 0x0, 0x1f)
DECLARE_INSN(fadd_d, 0xd3, 0x1f1ff)
DECLARE_INSN(sltiu, 0x193, 0x3ff)
DECLARE_INSN(mtpcr, 0x1fb, 0x1ffff)
DECLARE_INSN(vlb, 0xb, 0x3fffff)
DECLARE_INSN(stop, 0x177, 0xffffffff)
DECLARE_INSN(vld, 0x18b, 0x3fffff)
DECLARE_INSN(c_slli, 0x19, 0x1c1f)
DECLARE_INSN(break, 0xf7, 0xffffffff)
DECLARE_INSN(cflush, 0x2fb, 0xffffffff)
DECLARE_INSN(fcvt_s_w, 0xe053, 0x3ff1ff)
DECLARE_INSN(vflstw, 0x150b, 0x1ffff)
DECLARE_INSN(mul, 0x433, 0x1ffff)
DECLARE_INSN(c_lw, 0xa, 0x1f)
DECLARE_INSN(vxcptevac, 0x237b, 0xf83fffff)
DECLARE_INSN(vlw, 0x10b, 0x3fffff)
DECLARE_INSN(vssegstw, 0x90f, 0xfff)
DECLARE_INSN(amominu_d, 0x19ab, 0x1ffff)
DECLARE_INSN(c_sdsp, 0x6, 0x1f)
DECLARE_INSN(utidx, 0x1f7, 0x7ffffff)
DECLARE_INSN(srli, 0x293, 0x3f03ff)
DECLARE_INSN(c_srli, 0x819, 0x1c1f)
DECLARE_INSN(c_ldsp, 0x4, 0x1f)
DECLARE_INSN(c_flw, 0x14, 0x1f)
DECLARE_INSN(c_srai32, 0x1419, 0x1c1f)
DECLARE_INSN(amominu_w, 0x192b, 0x1ffff)
DECLARE_INSN(divuw, 0x6bb, 0x1ffff)
DECLARE_INSN(mulw, 0x43b, 0x1ffff)
DECLARE_INSN(vssegstd, 0x98f, 0xfff)
DECLARE_INSN(srlw, 0x2bb, 0x1ffff)
DECLARE_INSN(vssegstb, 0x80f, 0xfff)
DECLARE_INSN(mftx_d, 0x1c0d3, 0x3fffff)
DECLARE_INSN(div, 0x633, 0x1ffff)
DECLARE_INSN(vtcfg, 0xc73, 0xf801ffff)
DECLARE_INSN(mftx_s, 0x1c053, 0x3fffff)
DECLARE_INSN(vssegsth, 0x88f, 0xfff)
DECLARE_INSN(vvcfgivl, 0xf3, 0x3ff)
DECLARE_INSN(j, 0x67, 0x7f)
DECLARE_INSN(fence, 0x12f, 0x3ff)
DECLARE_INSN(vsw, 0x10f, 0x3fffff)
DECLARE_INSN(fnmsub_s, 0x4b, 0x1ff)
DECLARE_INSN(vfssegstd, 0xd8f, 0xfff)
DECLARE_INSN(fcvt_l_s, 0x8053, 0x3ff1ff)
DECLARE_INSN(fle_s, 0x17053, 0x1ffff)
DECLARE_INSN(fence_v_l, 0x22f, 0x3ff)
DECLARE_INSN(vsb, 0xf, 0x3fffff)
DECLARE_INSN(mffsr, 0x1d053, 0x7ffffff)
DECLARE_INSN(fdiv_s, 0x3053, 0x1f1ff)
DECLARE_INSN(vlstbu, 0x120b, 0x1ffff)
DECLARE_INSN(vsetvl, 0x2f3, 0x3fffff)
DECLARE_INSN(fle_d, 0x170d3, 0x1ffff)
DECLARE_INSN(fence_i, 0xaf, 0x3ff)
DECLARE_INSN(vlsegbu, 0x220b, 0x1ffff)
DECLARE_INSN(fnmsub_d, 0xcb, 0x1ff)
DECLARE_INSN(addw, 0x3b, 0x1ffff)
DECLARE_INSN(sll, 0xb3, 0x1ffff)
DECLARE_INSN(xor, 0x233, 0x1ffff)
DECLARE_INSN(sub, 0x10033, 0x1ffff)
DECLARE_INSN(eret, 0x27b, 0xffffffff)
DECLARE_INSN(blt, 0x263, 0x3ff)
DECLARE_INSN(vsstw, 0x110f, 0x1ffff)
DECLARE_INSN(mtfsr, 0x1f053, 0x3fffff)
DECLARE_INSN(vssth, 0x108f, 0x1ffff)
DECLARE_INSN(rem, 0x733, 0x1ffff)
DECLARE_INSN(srliw, 0x29b, 0x3f83ff)
DECLARE_INSN(lui, 0x37, 0x7f)
DECLARE_INSN(vsstb, 0x100f, 0x1ffff)
DECLARE_INSN(fcvt_s_lu, 0xd053, 0x3ff1ff)
DECLARE_INSN(vsstd, 0x118f, 0x1ffff)
DECLARE_INSN(addi, 0x13, 0x3ff)
DECLARE_INSN(vfmst, 0x1173, 0x1ffff)
DECLARE_INSN(mulh, 0x4b3, 0x1ffff)
DECLARE_INSN(fmul_s, 0x2053, 0x1f1ff)
DECLARE_INSN(vlsegsthu, 0xa8b, 0xfff)
DECLARE_INSN(srai, 0x10293, 0x3f03ff)
DECLARE_INSN(amoand_d, 0x9ab, 0x1ffff)
DECLARE_INSN(flt_d, 0x160d3, 0x1ffff)
DECLARE_INSN(sraw, 0x102bb, 0x1ffff)
DECLARE_INSN(fmul_d, 0x20d3, 0x1f1ff)
DECLARE_INSN(ld, 0x183, 0x3ff)
DECLARE_INSN(ori, 0x313, 0x3ff)
DECLARE_INSN(flt_s, 0x16053, 0x1ffff)
DECLARE_INSN(addiw, 0x1b, 0x3ff)
DECLARE_INSN(amoand_w, 0x92b, 0x1ffff)
DECLARE_INSN(feq_s, 0x15053, 0x1ffff)
DECLARE_INSN(fsgnjx_d, 0x70d3, 0x1ffff)
DECLARE_INSN(sra, 0x102b3, 0x1ffff)
DECLARE_INSN(c_lwsp, 0x5, 0x1f)
DECLARE_INSN(bge, 0x2e3, 0x3ff)
DECLARE_INSN(c_add3, 0x1c, 0x31f)
DECLARE_INSN(sraiw, 0x1029b, 0x3f83ff)
DECLARE_INSN(vssegd, 0x218f, 0x1ffff)
DECLARE_INSN(srl, 0x2b3, 0x1ffff)
DECLARE_INSN(venqcmd, 0x2b7b, 0xf801ffff)
DECLARE_INSN(vfmts, 0x1973, 0x1ffff)
DECLARE_INSN(venqimm1, 0x2f7b, 0xf801ffff)
DECLARE_INSN(fsgnjx_s, 0x7053, 0x1ffff)
DECLARE_INSN(vfmsv, 0x973, 0x3fffff)
DECLARE_INSN(venqimm2, 0x337b, 0xf801ffff)
DECLARE_INSN(fcvt_d_wu, 0xf0d3, 0x3ff1ff)
DECLARE_INSN(vxcptrestore, 0x77b, 0xf83fffff)
DECLARE_INSN(vmts, 0x1873, 0x1ffff)
DECLARE_INSN(or, 0x333, 0x1ffff)
DECLARE_INSN(rdinstret, 0xa77, 0x7ffffff)
DECLARE_INSN(fcvt_wu_d, 0xb0d3, 0x3ff1ff)
DECLARE_INSN(subw, 0x1003b, 0x1ffff)
DECLARE_INSN(jalr_c, 0x6b, 0x3ff)
DECLARE_INSN(fmax_s, 0x19053, 0x1ffff)
DECLARE_INSN(amomaxu_d, 0x1dab, 0x1ffff)
DECLARE_INSN(c_slliw, 0x1819, 0x1c1f)
DECLARE_INSN(jalr_j, 0x16b, 0x3ff)
DECLARE_INSN(c_fld, 0x15, 0x1f)
DECLARE_INSN(vlstw, 0x110b, 0x1ffff)
DECLARE_INSN(vlsth, 0x108b, 0x1ffff)
DECLARE_INSN(xori, 0x213, 0x3ff)
DECLARE_INSN(jalr_r, 0xeb, 0x3ff)
DECLARE_INSN(amomaxu_w, 0x1d2b, 0x1ffff)
DECLARE_INSN(fcvt_wu_s, 0xb053, 0x3ff1ff)
DECLARE_INSN(vlstb, 0x100b, 0x1ffff)
DECLARE_INSN(vlstd, 0x118b, 0x1ffff)
DECLARE_INSN(c_ld0, 0x8012, 0x801f)
DECLARE_INSN(rdtime, 0x677, 0x7ffffff)
DECLARE_INSN(andi, 0x393, 0x3ff)
DECLARE_INSN(clearpcr, 0x7b, 0x3ff)
DECLARE_INSN(venqcnt, 0x377b, 0xf801ffff)
DECLARE_INSN(fsgnjn_d, 0x60d3, 0x1ffff)
DECLARE_INSN(fnmadd_s, 0x4f, 0x1ff)
DECLARE_INSN(jal, 0x6f, 0x7f)
DECLARE_INSN(lwu, 0x303, 0x3ff)
DECLARE_INSN(vlsegstbu, 0xa0b, 0xfff)
DECLARE_INSN(c_beq, 0x10, 0x1f)
DECLARE_INSN(vlhu, 0x28b, 0x3fffff)
DECLARE_INSN(vfsstd, 0x158f, 0x1ffff)
DECLARE_INSN(c_bne, 0x11, 0x1f)
DECLARE_INSN(fnmadd_d, 0xcf, 0x1ff)
DECLARE_INSN(amoadd_d, 0x1ab, 0x1ffff)
DECLARE_INSN(c_sw, 0xd, 0x1f)
DECLARE_INSN(amomax_w, 0x152b, 0x1ffff)
DECLARE_INSN(c_move, 0x2, 0x801f)
DECLARE_INSN(fmovn, 0xef7, 0x1ffff)
DECLARE_INSN(c_fsw, 0x16, 0x1f)
DECLARE_INSN(c_j, 0x8002, 0x801f)
DECLARE_INSN(mulhsu, 0x533, 0x1ffff)
DECLARE_INSN(c_sd, 0xc, 0x1f)
DECLARE_INSN(amoadd_w, 0x12b, 0x1ffff)
DECLARE_INSN(fcvt_d_lu, 0xd0d3, 0x3ff1ff)
DECLARE_INSN(amomax_d, 0x15ab, 0x1ffff)
DECLARE_INSN(fsd, 0x1a7, 0x3ff)
DECLARE_INSN(fcvt_w_d, 0xa0d3, 0x3ff1ff)
DECLARE_INSN(fmovz, 0xaf7, 0x1ffff)
DECLARE_INSN(feq_d, 0x150d3, 0x1ffff)
DECLARE_INSN(c_or3, 0x21c, 0x31f)
DECLARE_INSN(vmvv, 0x73, 0x3fffff)
DECLARE_INSN(vfssegstw, 0xd0f, 0xfff)
DECLARE_INSN(slt, 0x133, 0x1ffff)
DECLARE_INSN(mxtf_d, 0x1e0d3, 0x3fffff)
DECLARE_INSN(sllw, 0xbb, 0x1ffff)
DECLARE_INSN(amoor_d, 0xdab, 0x1ffff)
DECLARE_INSN(slti, 0x113, 0x3ff)
DECLARE_INSN(remu, 0x7b3, 0x1ffff)
DECLARE_INSN(flw, 0x107, 0x3ff)
DECLARE_INSN(remw, 0x73b, 0x1ffff)
DECLARE_INSN(sltu, 0x1b3, 0x1ffff)
DECLARE_INSN(slli, 0x93, 0x3f03ff)
DECLARE_INSN(c_and3, 0x31c, 0x31f)
DECLARE_INSN(vssegw, 0x210f, 0x1ffff)
DECLARE_INSN(amoor_w, 0xd2b, 0x1ffff)
DECLARE_INSN(vsd, 0x18f, 0x3fffff)
DECLARE_INSN(beq, 0x63, 0x3ff)
DECLARE_INSN(fld, 0x187, 0x3ff)
DECLARE_INSN(mxtf_s, 0x1e053, 0x3fffff)
DECLARE_INSN(fsub_s, 0x1053, 0x1f1ff)
DECLARE_INSN(and, 0x3b3, 0x1ffff)
DECLARE_INSN(vtcfgivl, 0x1f3, 0x3ff)
DECLARE_INSN(lbu, 0x203, 0x3ff)
DECLARE_INSN(vf, 0x3f3, 0xf80003ff)
DECLARE_INSN(vlsegstw, 0x90b, 0xfff)
DECLARE_INSN(syscall, 0x77, 0xffffffff)
DECLARE_INSN(fsgnj_s, 0x5053, 0x1ffff)
DECLARE_INSN(c_addi, 0x1, 0x1f)
DECLARE_INSN(vfmvv, 0x173, 0x3fffff)
DECLARE_INSN(vlstwu, 0x130b, 0x1ffff)
DECLARE_INSN(c_sub3, 0x11c, 0x31f)
DECLARE_INSN(vsh, 0x8f, 0x3fffff)
DECLARE_INSN(vlsegstb, 0x80b, 0xfff)
DECLARE_INSN(vxcptsave, 0x37b, 0xf83fffff)
DECLARE_INSN(vlsegstd, 0x98b, 0xfff)
DECLARE_INSN(vflsegd, 0x258b, 0x1ffff)
DECLARE_INSN(vflsegw, 0x250b, 0x1ffff)
DECLARE_INSN(vlsegsth, 0x88b, 0xfff)
DECLARE_INSN(fsgnj_d, 0x50d3, 0x1ffff)
DECLARE_INSN(vflsegstw, 0xd0b, 0xfff)
DECLARE_INSN(c_sub, 0x801a, 0x801f)
DECLARE_INSN(mulhu, 0x5b3, 0x1ffff)
DECLARE_INSN(fence_v_g, 0x2af, 0x3ff)
DECLARE_INSN(vmsv, 0x873, 0x3fffff)
DECLARE_INSN(vmst, 0x1073, 0x1ffff)
DECLARE_INSN(setpcr, 0xfb, 0x3ff)
DECLARE_INSN(rdnpc, 0x26b, 0x7ffffff)
DECLARE_INSN(vxcpthold, 0x277b, 0xffffffff)
DECLARE_INSN(fcvt_s_l, 0xc053, 0x3ff1ff)
DECLARE_INSN(vflsegstd, 0xd8b, 0xfff)
DECLARE_INSN(c_add, 0x1a, 0x801f)
DECLARE_INSN(fcvt_lu_d, 0x90d3, 0x3ff1ff)
DECLARE_INSN(vfld, 0x58b, 0x3fffff)
DECLARE_INSN(fsub_d, 0x10d3, 0x1f1ff)
DECLARE_INSN(fmadd_s, 0x43, 0x1ff)
DECLARE_INSN(fcvt_w_s, 0xa053, 0x3ff1ff)
DECLARE_INSN(vssegh, 0x208f, 0x1ffff)
DECLARE_INSN(fsqrt_s, 0x4053, 0x3ff1ff)
DECLARE_INSN(vxcptkill, 0xb7b, 0xffffffff)
DECLARE_INSN(c_srai, 0x1019, 0x1c1f)
DECLARE_INSN(amomin_w, 0x112b, 0x1ffff)
DECLARE_INSN(fsgnjn_s, 0x6053, 0x1ffff)
DECLARE_INSN(c_slli32, 0x419, 0x1c1f)
DECLARE_INSN(vlsegwu, 0x230b, 0x1ffff)
DECLARE_INSN(vfsw, 0x50f, 0x3fffff)
DECLARE_INSN(amoswap_d, 0x5ab, 0x1ffff)
DECLARE_INSN(fsqrt_d, 0x40d3, 0x3ff1ff)
DECLARE_INSN(vflw, 0x50b, 0x3fffff)
DECLARE_INSN(fdiv_d, 0x30d3, 0x1f1ff)
DECLARE_INSN(fmadd_d, 0xc3, 0x1ff)
DECLARE_INSN(divw, 0x63b, 0x1ffff)
DECLARE_INSN(amomin_d, 0x11ab, 0x1ffff)
DECLARE_INSN(divu, 0x6b3, 0x1ffff)
DECLARE_INSN(amoswap_w, 0x52b, 0x1ffff)
DECLARE_INSN(vfsd, 0x58f, 0x3fffff)
DECLARE_INSN(fadd_s, 0x53, 0x1f1ff)
DECLARE_INSN(vlsegb, 0x200b, 0x1ffff)
DECLARE_INSN(fcvt_l_d, 0x80d3, 0x3ff1ff)
DECLARE_INSN(vlsegd, 0x218b, 0x1ffff)
DECLARE_INSN(vlsegh, 0x208b, 0x1ffff)
DECLARE_INSN(sw, 0x123, 0x3ff)
DECLARE_INSN(fmsub_s, 0x47, 0x1ff)
DECLARE_INSN(vfssegw, 0x250f, 0x1ffff)
DECLARE_INSN(c_addiw, 0x1d, 0x1f)
DECLARE_INSN(lhu, 0x283, 0x3ff)
DECLARE_INSN(sh, 0xa3, 0x3ff)
DECLARE_INSN(vlsegw, 0x210b, 0x1ffff)
DECLARE_INSN(fsw, 0x127, 0x3ff)
DECLARE_INSN(vlbu, 0x20b, 0x3fffff)
DECLARE_INSN(sb, 0x23, 0x3ff)
DECLARE_INSN(fmsub_d, 0xc7, 0x1ff)
DECLARE_INSN(vlseghu, 0x228b, 0x1ffff)
DECLARE_INSN(vssegb, 0x200f, 0x1ffff)
DECLARE_INSN(vfssegd, 0x258f, 0x1ffff)
DECLARE_INSN(sd, 0x1a3, 0x3ff)
