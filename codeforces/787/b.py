def main():
    n, m = map(int, input().split())
    ans = False
    for _ in range(m):
        group = list(map(int, input().split()))[1:]
        group = set(group)

        safe = False
        for x in group:
            if -x in group:
                safe = True

        ans = ans or (not safe)

    print("YES" if ans else "NO")

main()
