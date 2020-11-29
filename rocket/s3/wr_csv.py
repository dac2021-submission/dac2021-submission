import random

f = open('tv.txt', 'w')
sample_count = 100000

for i in range(sample_count):
  rs = random.randrange(16)
  rd = random.randrange(16)
  rt = random.randrange(16)
  imm1 = random.randrange(1 << 11)
  imm2 = random.randrange(16)
  imm3 = random.randrange(1 << 8)
  addi = f"{imm1:#0{5}x}" + hex(rs)[-1] + "0113 \n"
  slti = f"{imm1:#0{5}x}" + hex(rs)[-1] + "2113 \n"
  andi = f"{imm1:#0{5}x}" + hex(rs)[-1] + "7113 \n"
  ori = f"{imm1:#0{5}x}" + hex(rs)[-1] + "6113 \n"
  xori = f"{imm1:#0{5}x}" + hex(rs)[-1] + "4113 \n"
  slli = "0x00" + hex(imm2)[-1] + hex(rs)[-1] + "1113 \n"
  srli = "0x00" + hex(imm2)[-1] + hex(rs)[-1] + "5113 \n"
  srai = "0x40" + hex(imm2)[-1] + hex(rs)[-1] + "0113 \n"
  # f.write(addi + andi + ori + xori + slli + srli + slti + srai)

  add = "0x00" + hex(rd)[-1] + hex(rs)[-1] + "0133 \n"
  sub = "0x40" + hex(rd)[-1] + hex(rs)[-1] + "0133 \n"
  sll = "0x00" + hex(rd)[-1] + hex(rs)[-1] + "1133 \n"
  slt = "0x00" + hex(rd)[-1] + hex(rs)[-1] + "2133 \n"
  sltu = "0x00" + hex(rd)[-1] + hex(rs)[-1] + "3133 \n"
  xor = "0x00" + hex(rd)[-1] + hex(rs)[-1] + "4133 \n"
  srl = "0x00" + hex(rd)[-1] + hex(rs)[-1] + "5133 \n"
  sra = "0x40" + hex(rd)[-1] + hex(rs)[-1] + "5133 \n"
  or_ = "0x00" + hex(rd)[-1] + hex(rs)[-1] + "6133 \n"
  and_ = "0x00" + hex(rd)[-1] + hex(rs)[-1] + "7133 \n"
  f.write(add + sub + sll + slt + sltu + xor + srl + sra + or_ + and_)