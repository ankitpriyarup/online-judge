def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    target = min(a)
    mods = set([x % k for x in a])
    if len(mods) != 1:
        print(-1)
        return

    ans = sum((x - target) // k for x in a)
    print(ans)

main()
