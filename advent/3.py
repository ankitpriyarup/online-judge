def solve(moves, case):
    s = set()
    s.add((0, 0))
    pos = [[0, 0], [0, 0]]
    santa = 0

    for c in moves:
        if c == '>':
            pos[santa][0] += 1
        elif c == '<':
            pos[santa][0] -= 1
        elif c == 'v':
            pos[santa][1] -= 1
        elif c == '^':
            pos[santa][1] += 1

        s.add((pos[santa][0], pos[santa][1]))
        # only switch santas if case = 1
        santa = case ^ santa

    return len(s)

def main():
    fin = open('3.in', 'r')
    moves = fin.readline().strip()
    fin.close()
    print "Part 1", solve(moves, 0)
    print "Part 2", solve(moves, 1)

if __name__ == '__main__':
    main()
