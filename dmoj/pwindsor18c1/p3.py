maxn = 1000000
prime = [True for _ in range(maxn + 1)]
prime[0] = prime[1] = False
for i in range(2, maxn):
    if not prime[i]:
        continue
    for j in range(i * i, maxn, i):
        prime[j] = False

n = int(input())
ans = 0
for _ in range(n):
    if not prime[int(input())]:
        ans += 1

print(ans)
