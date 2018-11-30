c, x, m = map(float, input().split())
c /= 2.0
ans = -1
for _ in range(6):
    speed, mpg = input().split()
    speed = int(speed)
    mpg = float(mpg)

    time = m / speed
    gallons = m / mpg
    fuel = gallons + time * x
    if fuel < c:
        ans = speed

if ans == -1:
    print('NO')
else:
    print('YES', ans)
