toggle_map = {'tgl': 'inc', 'inc': 'dec', 'dec': 'inc', 'cpy': 'jnz', 'jnz': 'cpy'}


def add_inst(commands, pc):
    if commands[pc][0] == 'inc' \
        and commands[pc + 1][0] == 'dec' \
        and commands[pc + 2][0] == 'jnz' \
        and commands[pc + 2][2] == '-2':
            return commands[pc][1], commands[pc + 1][1]
    elif commands[pc][0] == 'dec' \
        and commands[pc + 1][0] == 'inc' \
        and commands[pc + 2][0] == 'jnz' \
        and commands[pc + 2][2] == '-2':
            return commands[pc + 1][1], commands[pc][1]
    else:
        return None, None

def run(commands, seed):
    registers = {k: 0 for k in 'abcd'}
    registers['a'] = seed

    inst_count = 0
    pc = 0
    clock = []

    while 0 <= pc < len(commands):
        command = commands[pc]
        # print(inst_count, pc, command, registers)
        inst_count += 1
        inc_pc = True

        big_reg, zero_reg = add_inst(commands, pc)
        if big_reg is not None:
            registers[big_reg] += registers[zero_reg]
            registers[zero_reg] = 0
            pc += 3
            inc_pc = False
        elif command[0] == 'cpy':
            value = registers[command[1]] if command[1] in registers else int(command[1])
            if command[2] in registers:
                registers[command[2]] = value
        elif command[0] == 'jnz':
            flag = registers[command[1]] if command[1] in registers else int(command[1])
            value = registers[command[2]] if command[2] in registers else int(command[2])
            if flag != 0:
                pc += value
                inc_pc = False
        elif command[0] == 'inc':
            registers[command[1]] += 1
        elif command[0] == 'dec':
            registers[command[1]] -= 1
        elif command[0] == 'tgl':
            value = registers[command[1]] if command[1] in registers else int(command[1])
            target_pc = pc + value
            if 0 <= target_pc < len(commands):
                commands[target_pc][0] = toggle_map[commands[target_pc][0]]
        elif command[0] == 'out':
            clock.append(registers['b'])
            if len(clock) >= 2 and clock[-1] == clock[-2] or len(clock) > 100:
                break

        if inc_pc:
            pc += 1

    return clock


def main():
    fin = open('25.in', 'r')
    commands = [line.strip().split() for line in fin]
    fin.close()

    for seed in range(1, 100000):
        if len(run(commands, seed)) >= 90:
            print(seed)

main()
