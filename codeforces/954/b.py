n = int(input())
s = input()
ans = n
for p in range(1, n):
    if 2 * p > n:
        break
    if s[:p] + s[:p] == s[:(2 * p)]:
        ans = min(ans, p + 1 + n - 2 * p)
print(ans)
