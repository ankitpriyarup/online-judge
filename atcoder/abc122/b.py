s = input()
n = len(s)
ans = 0
for i in range(n):
    for j in range(i + 1, n + 1):
        if all(c in 'ATCG' for c in s[i:j]):
            ans = max(ans, j - i)

print(ans)
