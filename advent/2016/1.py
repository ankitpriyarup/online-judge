dirs = [(0, 1), (-1, 0), (0, -1), (1, 0)]

def main():
    commands = list(map(lambda x: x.strip(), input().split(',')))
    pos = [0, 0]
    d = 0

    for c in commands:
        a = c[0]
        b = int(c[1:])
        if a == 'R':
            pos[0] += b * dirs[d][0]
            pos[1] += b * dirs[d][1]
            d = (d + 1) % 4
        else:
            # flip between 0 and 2, 1 and 3
            if d == 0 or d == 2:
                d = 2 - d
            else:
                d = 4 - d

            pos[0] += b * dirs[d][0]
            pos[1] += b * dirs[d][1]
            d = (d + 1) % 4

    print(pos, sum(pos))

main()
