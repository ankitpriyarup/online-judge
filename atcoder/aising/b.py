n = int(input())
a, b = map(int, input().split())
f = [0, 0, 0]
for x in map(int, input().split()):
    if x <= a:
        f[0] += 1
    elif x <= b:
        f[1] += 1
    else:
        f[2] += 1
print(min(f))
