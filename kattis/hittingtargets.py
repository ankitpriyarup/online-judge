def hit(target, x, y):
    if target[0] == 'rectangle':
        x1, y1, x2, y2 = target[1:]
        return x1 <= x <= x2 and y1 <= y <= y2
    else:
        dx = x - target[1]
        dy = y - target[2]
        r = target[3]
        return dx * dx + dy * dy <= r * r
m = int(input())
targets = []
for _ in range(m):
    targets.append(list(input().split()))
    targets[-1] = [targets[-1][0]] + list(map(int, targets[-1][1:]))

q = int(input())
for _ in range(q):
    x, y = map(int, input().split())
    ans = sum(hit(target, x, y) for target in targets)
    print(ans)
