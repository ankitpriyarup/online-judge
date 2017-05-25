import sys

def main():
    forwards = {}
    backwards = {}

    for line in sys.stdin.readlines():
        tokens = line.strip().split()
        if tokens[0] == 'def':
            name = tokens[1]
            val = int(tokens[2])

            if name in forwards:
                oldval = forwards[name]
                del forwards[name]
                del backwards[oldval]

            forwards[name] = val
            backwards[val] = name
        elif tokens[0] == 'clear':
            forwards = {}
            backwards = {}
        else:
            command = ' '.join(tokens[1:])
            tokens[0] = '+'
            tokens = tokens[:-1]
            ans = 0

            for i in range(0, len(tokens), 2):
                sign = tokens[i]
                val = tokens[i + 1]
                if val not in forwards.keys():
                    ans = ''
                    break

                ans += (1 if sign == '+' else -1) * forwards[val]

            print(command, backwards.get(ans, 'unknown'))

main()
