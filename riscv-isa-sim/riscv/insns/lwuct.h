require_rv64;
REQUIRE_TAG(RS1 + insn.it_imm(), insn.it_etag());
WRITE_RD(MMU.load_uint32(RS1 + insn.it_imm()));