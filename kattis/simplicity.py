from collections import Counter
import string

s = input()
c = Counter(s)
n = len(s)

ans = n
for a in string.ascii_lowercase:
    ans = min(ans, n - c[a])
    for b in string.ascii_lowercase:
        if a == b:
            continue

        ans = min(ans, n - c[a] - c[b])

print(ans)
