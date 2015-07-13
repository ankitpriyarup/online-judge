n = int(raw_input())
ans = 0

for i in xrange(n):
    a = map(int, raw_input().split())
    if sum(a) >= 2:
        ans += 1

print ans
