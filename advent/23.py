HLF, TPL, INC, JMP, JIE, JIO = 0, 1, 2, 3, 4, 5
def parse(inst):
    inst = inst.split()
    register = inst[1][0]
    if inst[0] == 'hlf':
        return (HLF, register)
    elif inst[0] == 'tpl':
        return (TPL, register)
    elif inst[0] == 'inc':
        return (INC, register)
    elif inst[0] == 'jmp':
        return (JMP, int(inst[1]))
    elif inst[0] == 'jie':
        return (JIE, register, int(inst[2]))
    else:
        return (JIO, register, int(inst[2]))

def main():
    fin = open('23.in', 'r')
    code = map(lambda x: parse(x.strip()), fin.readlines())

    pc = 0
    end = len(code)

    registers = {'a': 1, 'b': 0}
    while pc >= 0 and pc < end:
        d = 0
        inst = code[pc]
        print inst
        if inst[0] == HLF:
            registers[inst[1]] /= 2
        elif inst[0] == TPL:
            registers[inst[1]] *= 3
        elif inst[0] == INC:
            registers[inst[1]] += 1
        elif inst[0] == JMP:
            d = inst[1]
        elif inst[0] == JIE:
            if registers[inst[1]] % 2 == 0:
                d = inst[2]
        elif inst[0] == JIO:
            if registers[inst[1]] == 1:
                d = inst[2]

        if d == 0:
            pc += 1
        else:
            pc += d

        print pc, registers

    print registers

if __name__ == '__main__':
    main()
