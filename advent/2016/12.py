import functools
from collections import defaultdict

def main():
    fin = open('12.in', 'r')
    #fin = open('12.samp', 'r')
    registers = {k: 0 for k in "abcd"}
    registers['c'] = 1
    commands = [line.strip().split() for line in fin]
    fin.close()
    pc = 0
    while pc < len(commands):
        command = commands[pc]
        # print(command)
        if command[0] == 'cpy':
            value = registers[command[1]] if command[1] in registers else int(command[1])
            registers[command[2]] = value
        elif command[0] == 'jnz':
            flag = registers[command[1]] if command[1] in registers else int(command[1])
            value = registers[command[2]] if command[2] in registers else int(command[2])
            if flag != 0:
                pc += value
                continue
        elif command[0] == 'inc':
            registers[command[1]] += 1
        elif command[0] == 'dec':
            registers[command[1]] -= 1

        pc += 1

    print(registers)

main()
