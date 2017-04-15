def all_q(l):
    return all(x == '?' for x in l)

def solve():
    r, c = map(int, input().split())
    cake = [list(input()) for _ in range(r)]

    source = 0

    for i in range(r):
        if not all_q(cake[i]):
            # find first non ?
            j = 0
            while cake[i][j] == '?':
                j += 1

            for k in range(j):
                cake[i][k] = cake[i][j]

            last = cake[i][j]
            for k in range(j + 1, c):
                if cake[i][k] == '?':
                    cake[i][k] = last
                else:
                    last = cake[i][k]

            source = i

    for i in range(source + 1, r):
        if all_q(cake[i]):
            cake[i] = cake[i - 1][:]

    for i in range(source - 1, -1, -1):
        if all_q(cake[i]):
            cake[i] = cake[i + 1][:]

    for row in cake:
        print(''.join(row))

def main():
    t = int(input())
    for tt in range(t):
        print('Case #{}:'.format(tt + 1))
        solve()

main()
