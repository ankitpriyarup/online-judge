def main():
    MAX = 86400
    n, t = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 1
    for x in a:
        t -= (MAX - x)
        if t <= 0:
            print(ans)
            return
        ans += 1

main()
