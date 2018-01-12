def main():
    n = int(input())
    ans = 0
    for _ in range(n):
        c, v = map(int, input().split())
        if v > 0:
            ans += c
    print(ans)

main()
