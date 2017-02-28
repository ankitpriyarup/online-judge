def main():
    fin = open('21.in', 'r')
    inp = list('fbgdceah')

    # fin = open('21.samp', 'r')
    # inp = list('decab')

    commands = [line.strip().split() for line in fin]

    for command in reversed(commands):
        print(inp)
        print(' '.join(command))
        if command[0] == 'swap':
            if command[1] == 'letter':
                x = inp.index(command[2])
                y = inp.index(command[-1])
            else:
                x = int(command[2])
                y = int(command[-1])

            inp[x], inp[y] = inp[y], inp[x]
        elif command[0] == 'reverse':
            x = int(command[2])
            y = int(command[-1])

            inp = inp[:x] + list(reversed(inp[x:y + 1])) + inp[y+1:]
        elif command[0] == 'move':
            target = int(command[2])
            x = int(command[-1])

            out = inp[x]
            inp = inp[:x] + inp[x + 1:]
            inp = inp[:target] + [out] + inp[target:]
        else:
            if command[1] == 'based':
                ind = inp.index(command[-1])
                for i in range(len(inp) - 1, -1, -1):
                    steps = i + 1 + (1 if i >= 4 else 0)
                    if (i + steps) % len(inp) == ind:
                        print(i, steps, ind)
                        steps %= len(inp)
                        inp = inp[steps:] + inp[:steps]
                        break
            else:
                is_left = command[1] == 'left'
                steps = int(command[-2])
                steps %= len(inp)
                if is_left:
                    inp = inp[-steps:] + inp[:-steps]
                else:
                    inp = inp[steps:] + inp[:steps]

        print(inp)

    print(''.join(inp))


main()
