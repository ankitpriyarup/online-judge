def main():
    n, m = map(int, input().split())
    c = [0 for _ in range(11)]
    for _ in range(m):
        a, b = map(int, input().split())
        c[b] += a

    ans = 0
    for x in range(10, -1, -1):
        take = min(n, c[x])
        ans += take * x
        n -= take

    print(ans)

main()
