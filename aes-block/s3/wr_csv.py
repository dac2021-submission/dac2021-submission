import random

f = open('tv_verilog_only.csv', 'w')
sample_count = 2048

key = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] 
counter = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] 

for i in range(sample_count):
  start_address = i*16
  for j in range(16):
    key[j] = random.randrange(256)
    counter[j] = random.randrange(256)
  
  addr_hi = int(i / 256)
  addr_lo = i % 256

  f.write("1, 0, 0xff02, " + f"{addr_lo:#0{4}x}" + "\n")
  f.write("1, 0, 0xff03, " + f"{addr_hi:#0{4}x}" + "\n")
  f.write("1, 0, 0xff04, 0x00\n")
  f.write("1, 0, 0xff05, 0x01\n")
  for j in range(13):
    f.write("1, 0, 0xff1" + hex(j)[-1] + f", {key[j]:#0{4}x}" + "\n")
  for j in range(13):
    f.write("1, 0, 0xff2" + hex(j)[-1] + f", {counter[j]:#0{4}x}" + "\n")
  f.write("1, 0, 0xff00, 0x01\n")
  f.write("1, 0, 0xff02, 0xf0\n")




  
