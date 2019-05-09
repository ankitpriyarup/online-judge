l, n = map(int, input().split())
# first depletes in increments of n
# second depletes in increments of n - (l % n)
# third depletes in increments of n - (n - (l % n)) % n
# in general, f0 = l
# f1 = n - (l % n)
# f2 = n - (f1 % n)

# 31 6
# 31 5
# 31 4
# 31 1

ans = 1
while l % n != 0:
    ans += 1
    n = n - (l % n)

print(ans)
