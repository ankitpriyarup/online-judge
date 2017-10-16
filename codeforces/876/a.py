def main():
    n = int(input())
    a = int(input())
    b = int(input())
    c = int(input())

    adj = [[0, a, b], [a, 0, c], [b, c, 0]]

    ans = 0
    pos = 0
    for _ in range(n - 1):
        dst = -1
        for j in range(3):
            if j == pos:
                continue
            if dst == -1 or adj[pos][j] < adj[pos][dst]:
                dst = j

        ans += adj[pos][dst]
        pos = dst

    print(ans)


main()
