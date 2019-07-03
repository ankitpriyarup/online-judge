import sys

print([len(str(5**x)) for x in range(10001)])

T = int(sys.stdin.readline())
for _ in range(T):
    a, b = map(int, sys.stdin.readline().split())
    m = min(a, b)
    ans = m
    if a > m:
        ans += len(str(2**(a-m)))
    elif b > m:
        ans += len(str(5**(b-m)))
    else:
        ans += 1
    print(ans)
