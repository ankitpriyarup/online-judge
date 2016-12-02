dirs = [(0, 1), (-1, 0), (0, -1), (1, 0)]

def main():
    commands = list(map(lambda x: x.strip(), input().split(',')))
    pos = [0, 0]
    d = 0
    visited = set()
    visited.add((0, 0))

    for c in commands:
        a = c[0]
        b = int(c[1:])
        new_pos = pos[:]
        if a == 'R':
            new_pos[0] += b * dirs[d][0]
            new_pos[1] += b * dirs[d][1]
            d = (d + 1) % 4
        else:
            # flip between 0 and 2, 1 and 3
            if d == 0 or d == 2:
                d = 2 - d
            else:
                d = 4 - d

            new_pos[0] += b * dirs[d][0]
            new_pos[1] += b * dirs[d][1]
            d = (d + 1) % 4
        
        for x in range(min(new_pos[0], pos[0]), max(new_pos[0], pos[0]) + 1):
            for y in range(min(new_pos[1], pos[1]), max(new_pos[1], pos[1]) + 1):
                if (x, y) in visited and (x, y) != tuple(pos):
                    print((x, y), abs(x) + abs(y))
                    return

                visited.add((x, y))

        pos = new_pos

main()
