a, b = map(int, input().split())
t = 0
while a > 0 and b > 0:
    if a <= 1 and b <= 1:
        break
    if a > b:
        a -= 2
        b += 1
    else:
        a += 1
        b -= 2
    t += 1

print(t)
