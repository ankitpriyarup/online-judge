from collections import Counter

s = input()
c = Counter(s)

n = len(s)
ans = n

for a in range(26):
    ans = min(ans, n - c[chr(a + ord('a'))])
    for b in range(a + 1, 26):
        ans = min(ans, n - c[chr(a + ord('a'))] - c[chr(b + ord('a'))])

print(ans)
