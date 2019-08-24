from collections import defaultdict

n, a, b = input().split()
n = int(n)

used = [x == y for x, y in zip(a, b)]

freq = defaultdict(int)
for i in range(n):
    if not used[i]:
        freq[a[i]] += 1

ans = 0
for i in range(n):
    if not used[i] and freq[b[i]] > 0:
        ans += 1
        freq[b[i]] -= 1

print(sum(used), ans)
