import sys

def main():
    defs = {}
    for line in sys.stdin:
        cmd = line.strip().split()
        if cmd[0] == 'define':
            defs[cmd[2]] = int(cmd[1])
        else:
            x, y, z = cmd[1:]
            if x not in defs or z not in defs:
                print('undefined')
            else:
                a = defs[x]
                b = defs[z]
                if y == '=':
                    print('true' if a == b else 'false')
                elif y == '<':
                    print('true' if a < b else 'false')
                elif y == '>':
                    print('true' if a > b else 'false')

main()
