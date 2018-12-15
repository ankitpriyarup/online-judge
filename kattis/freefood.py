n = int(input())
c = [0 for _ in range(500)]
for _ in range(n):
    a, b = map(int, input().split())
    for i in range(a, b + 1):
        c[i] += 1

ans = 0
for i in range(1, 366):
    if c[i] > 0:
        ans += 1
print(ans)
