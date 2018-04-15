T = int(input())
for _ in range(T):
    s = input()
    n = len(s)
    ans = 0
    for i in range(1, n + 1):
        frag = int(s[:i])
        ans = max(ans, bin(frag).count('1'))
    print(ans)

