n, x = map(int, input().split())

distress = 0
for _ in range(n):
    s, v = input().split()
    v = int(v)
    if s == '+':
        x += v
    else:
        if x < v:
            distress += 1
        else:
            x -= v

print(x, distress)
