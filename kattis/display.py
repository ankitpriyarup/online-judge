import sys

keys = ["+---+\n|   |\n|   |\n+   +\n|   |\n|   |\n+---+",
        "    +\n    |\n    |\n    +\n    |\n    |\n    +",
        "+---+\n    |\n    |\n+---+\n|    \n|    \n+---+",
        "+---+\n    |\n    |\n+---+\n    |\n    |\n+---+",
        "+   +\n|   |\n|   |\n+---+\n    |\n    |\n    +",
        "+---+\n|    \n|    \n+---+\n    |\n    |\n+---+",
        "+---+\n|    \n|    \n+---+\n|   |\n|   |\n+---+",
        "+---+\n    |\n    |\n    +\n    |\n    |\n    +",
        "+---+\n|   |\n|   |\n+---+\n|   |\n|   |\n+---+",
        "+---+\n|   |\n|   |\n+---+\n    |\n    |\n+---+"]

def put(disp, v, c):
    key = keys[v].split('\n')
    for i in range(7):
        for j in range(5):
            disp[i][j + c] = key[i][j]

def solve(time):
    disp = [[' ' for _ in range(29)] for _ in range(7)]
    put(disp, int(time[0]), 0)
    put(disp, int(time[1]), 7)
    disp[2][14] = 'o'
    disp[4][14] = 'o'
    put(disp, int(time[3]), 17)
    put(disp, int(time[4]), 24)
    for row in disp:
        print(''.join(row))
    print()
    print()

for line in sys.stdin:
    line = line.strip()
    if line == 'end':
        print(line)
        break
    solve(line)
