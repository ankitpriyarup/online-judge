import sys
n = int(sys.stdin.readline())
s = sys.stdin.readline()

a = []
for i in range(1, n):
    if s[i] != '0':
        a.append((max(i, n - i), i))

a.sort()
ans = int(s)
for l, i in a:
    if l > a[0][0]:
        break
    ans = min(ans, int(s[:i]) + int(s[i:]))

print(ans)
