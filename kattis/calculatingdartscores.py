s = set()
for i in range(1, 20 + 1):
    s.add(i)
    s.add(2 * i)
    s.add(3 * i)

n = int(input())
ans = []
if n in s:
    ans = [n]

for x in s:
    if ans:
        break

    y = n - x
    if y in s:
        ans = [x, y]
        break

    for y in s:
        z = n - x - y
        if z in s:
            ans = [x, y, z]
            break

if ans:
    for x in ans:
        if x % 3 == 0:
            print('triple', x // 3)
        elif x % 2 == 0:
            print('double', x // 2)
        else:
            print('single', x)
else:
    print("impossible")
