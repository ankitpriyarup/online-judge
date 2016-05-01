d, h, v, e = map(int, input().split())
radius = d / 2
PI = 3.1415926535897
e *= PI * radius * radius

if e >= v:
    print("NO")
else:
    rate = v - e
    volume = h * PI * radius * radius

    print("YES")
    print(volume/rate)
