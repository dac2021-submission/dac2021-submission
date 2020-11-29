f = open("./freechips.rocketchip.system.DefaultRV32Config.v", "r")

rls = f.readlines()
new_file = f.open("out", "w")
for l in rls:
    if l.find("endmodule") != -1:
        new_file.write(l)
        new_file.close()
    elif l.find("module") != -1:
        l1 = l.split()[1]
        new_file = f.open(l1[:-1] + ".v", "w")
        new_file.write(l)
    else:
        new_file.write(l)

        
    