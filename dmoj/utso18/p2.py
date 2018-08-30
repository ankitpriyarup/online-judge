a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

ans = 0
for i, x in enumerate(c):
    if b[i] == a[(i + 2) % 3]:
        ans += max(0, x)
print(ans)
