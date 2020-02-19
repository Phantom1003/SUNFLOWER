import sys

srcfile = open(sys.argv[1], 'r')
dstfile = open(sys.argv[1][:-2]+'_s.c', 'w')

sfunctions=[]

insfunc = False
brace = 0
name = ""

for line in srcfile:

    if (insfunc):
        for c in line:
            if c == '{':
                brace += 1
            elif c == '}':
                brace -= 1
        dstfile.write(line)
        if not brace:
            dstfile.write('void '+ name + '_end() {}\n')
            insfunc = False

    elif (("SFUNC" in line) and not insfunc):
        start = line.find("SFUNC")
        end   = line.find("(")
        name  = line[start+5:end].replace(' ', '')
        sfunctions.append(name)
        print('Security function: ' + name)
        dstfile.write(line.replace('SFUNC', ''))
        insfunc = True
        brace = 0
        for c in line:
            if c == '{':
                brace += 1
            elif c == '}':
                brace -= 1
        if not brace:
            dstfile.write('void '+ name + '_end() {}\n')
            insfunc = False
    elif ((" main " in line) or (" main(" in line)):
        dstfile.write(line)
        for name in sfunctions:
            dstfile.write("printf(\"Add function: " + name + "\\n\");\n" )
            dstfile.write("add_enclave(" + name + ", " + name + "_end);\n")
            print("Add enclave: " + name)
    else:
        dstfile.write(line)
srcfile.close()
dstfile.close()


