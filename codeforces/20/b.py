from math import sqrt

a, b, c = map(int, input().split())
disc = b * b - 4 * a * c

if a == 0 and b == 0 and c == 0:
    print(-1)
elif a == 0 and b == 0 or disc < 0:
    print(0)
elif a == 0:
    print(1)
    # y = bx + c
    # -c / b
    print(-c / b)
elif disc == 0:
    print(1)
    print(-b / 2 / a)
else:
    print(2)
    res = [(-b - sqrt(disc)) / (2.0 * a), (-b + sqrt(disc)) / (2.0 * a)]
    res.sort()
    print('{:7f}'.format(res[0]))
    print('{:7f}'.format(res[1]))
