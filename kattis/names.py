def main():
    s = input()
    n = len(s)
    ans = n
    for start in range(n):
        p0 = start
        p1 = n - 1
        moves = start
        while p0 < p1:
            moves += int(s[p0] != s[p1])
            p0 += 1
            p1 -= 1
        ans = min(ans, moves)
    print(ans)

main()
