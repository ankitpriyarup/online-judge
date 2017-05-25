def is_boom(s):
    breaks = 0
    comp = []
    for i, c in enumerate(s):
        if i > 0 and c == s[i - 1]:
            pass
        else:
            comp.append(c)

    n = len(comp)
    for i in range(1, n - 1):
        if comp[i - 1] < comp[i] and comp[i] > comp[i + 1]:
            breaks += 1
        elif comp[i - 1] > comp[i] and comp[i] < comp[i + 1]:
            breaks += 1

    return breaks == 1

def transpose(g):
    out = []
    for i in range(70):
        out.append(''.join(s[i] for s in g))

    return out

def main():
    fin = open('boomerang.txt', 'r')
    grid = []
    for line in fin:
        grid.append(line.strip())

    best = ''
    for row in grid:
        for i in range(70):
            for j in range(i + 1, 71):
                sub = row[i:j]
                if is_boom(sub) and len(sub) > len(best):
                    print(sub)
                    best = sub

    print('ANS', best)
    best = ''

    grid = transpose(grid)
    for row in grid:
        for i in range(70):
            for j in range(i + 1, 71):
                sub = row[i:j]
                if is_boom(sub) and len(sub) > len(best):
                    print(sub)
                    best = sub

    print('ANS', best)

main()
