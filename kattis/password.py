def main():
    n = int(input())
    l = []
    for _ in range(n):
        _, p = input().split()
        p = float(p)
        l.append(p)

    l.sort(reverse=True)
    ans = 0.0
    for i in range(n):
        ans += (i + 1) * l[i]

    print(ans)
main()
