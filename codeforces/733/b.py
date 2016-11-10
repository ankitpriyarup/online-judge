n = int(input())

left, right = [], []
for _ in range(n):
    l, r = map(int, input().split())
    left.append(l)
    right.append(r)

lsum = sum(left)
rsum = sum(right)
beauty = abs(lsum - rsum)
ans = -1
for i in range(n):
    new_beauty = abs(lsum - left[i] + right[i] - (rsum - right[i] + left[i]))
    if new_beauty > beauty:
        ans = i
        beauty = new_beauty

print(ans + 1)
