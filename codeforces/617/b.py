n = int(input())
a = list(map(int, input().split()))
ones = []
for i, x in enumerate(a):
    if x == 1:
        ones.append(i)

ans = 1
for i in range(1, len(ones)):
    ans *= (ones[i] - ones[i - 1])

if len(ones) == 0:
    print(0)
else:
    print(ans)
