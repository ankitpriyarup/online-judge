def main():
    n, m = map(int, input().split())
    bus = [[None for _ in range(4)] for _ in range(n)]
    half = 2 * n
    for i in range(0, 2 * n, 2):
        row = i // 2
        bus[row][0] = i + 1
        bus[row][3] = i + 2
        bus[row][1] = half + i + 1
        bus[row][2] = half + i + 2

    out = []
    for row in bus:
        if row[1] <= m:
            out.append(row[1])
        if row[0] <= m:
            out.append(row[0])
        if row[2] <= m:
            out.append(row[2])
        if row[3] <= m:
            out.append(row[3])

    print(' '.join(str(x) for x in out))

main()
