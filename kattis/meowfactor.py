n = int(input())
ans = 1
for x in range(2, 128):
    if n % (x**9) == 0:
        ans = x
print(ans)
