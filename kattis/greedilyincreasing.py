n = int(input())
last = -1
out = []
for x in map(int, input().split()):
    if x > last:
        last = x
        out.append(x)

print(len(out))
print(' '.join(str(x) for x in out))


