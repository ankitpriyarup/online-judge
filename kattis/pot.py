n = int(input())
ans = 0
for _ in range(n):
    s = int(input())
    p = s % 10
    s //= 10
    ans += pow(s, p)
print(ans)
