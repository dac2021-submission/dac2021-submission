f = open('tv_i.csv', 'w')
d_in = [i for i in range(488*2000)]
d_ptr = 0
for i in range(3913):
  f.write("0, 1, " + str(d_in[d_ptr] % 127) + "\n")
  d_ptr += 1
for i in range(481):
  f.write("1, 0, 0 \n")
  f.write("0, 1, " + str(d_in[d_ptr] % 127) + "\n")
  d_ptr += 1

for j in range(101):
  for i in range(7):
    f.write("0, 1, " + str(d_in[d_ptr] % 127) + "\n")
    d_ptr += 1

  for i in range(481):
    f.write("1, 0, 0\n")
    f.write("0, 1, " + str(d_in[d_ptr] % 127) + "\n") 
    d_ptr += 1
