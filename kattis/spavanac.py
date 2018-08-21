h, m = map(int, input().split())
m -= 45
while m < 0:
    m += 60
    h -= 1
while h < 0:
    h += 24
print(h, m)
