file1 = open('./compute.cc', 'r')
lines = file1.readlines()
file1.close()
outlines = []
i = 0
for l in lines:
    if l.find("while") > -1:
        break
    if l.find("if (") == -1:
        continue
    res = l.split("(")
    decode_res = res[1]
    print(decode_res[12:-1])
    outlines.append(decode_res[12:] + f" = {i},\n")
    i += 1

file2 = open('./tmp', 'w')
file2.writelines(outlines)
file2.close()
    