n, x = map(int, input().split())
a, b = float('-inf'), float('inf')
for _ in range(n):
    aa, bb = sorted(map(int, input().split()))
    a = max(a, aa)
    b = min(b, bb)

if b < a:
    print(-1)
elif a <= x and x <= b:
    print(0)
else:
    print(min(abs(x - a), abs(x - b)))
