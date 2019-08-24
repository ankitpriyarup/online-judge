n = int(input())
a = list(map(int, input().split()))
s = 0
for x in a:
    s += 1.0 / x

s = 1.0 / s
print('{:.9f}'.format(s))
