import sys

ans = 0
for line in sys.stdin:
    a, b, c = map(int, line.strip().split('x'))
    perims = [2 * (a + b), 2 * (b + c), 2 * (a + c)]
    vol = a * b * c
    ans += min(perims) + vol


    
print(ans)
