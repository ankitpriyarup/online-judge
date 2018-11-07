corr = int(input())
a = input()
b = input()
n = len(a)
incorr = n - corr
ans = 0
for x, y in zip(a, b):
    if x == y and corr > 0:
        ans += 1
        corr -= 1
    elif x != y and incorr > 0:
        ans += 1
        incorr -= 1

print(ans)

