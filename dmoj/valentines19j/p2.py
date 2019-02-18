t = int(input())
ans = 0
for _ in range(t):
    r, g, b = map(int, input().split())
    if 240 <= r <= 255 and 0 <= g <= 200 and 95 <= b <= 220:
        ans += 1
print(ans)
