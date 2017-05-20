n, k = map(int, input().split())
b = map(int, input().split())
c = [i for i, x in enumerate(b) if x == 1]

ans = float('inf')
for i in range(1, len(c)):
    ans = min(ans, c[i - 1] + k * (c[i] - c[i - 1]))
    
print(ans)
