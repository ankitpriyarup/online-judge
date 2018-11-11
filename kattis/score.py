def parse(t):
    h, m = t.split(':')
    return int(h) * 60 + int(m)

def fmt(x):
    h = x // 60
    m = x % 60
    return '{:d}:{:02d}'.format(h, m)

scores = [0, 0]
ans = [0, 0]
n = int(input())
last = 0
for _ in range(n):
    team, pts, time = input().split()
    time = parse(time)
    pts = int(pts)
    delta = time - last
    if scores[0] > scores[1]:
        ans[0] += delta
    elif scores[0] < scores[1]:
        ans[1] += delta
    if team == 'H':
        scores[0] += pts
    else:
        scores[1] += pts
    last = time

end = 32 * 60
delta = end - last
if scores[0] > scores[1]:
    ans[0] += delta
elif scores[0] < scores[1]:
    ans[1] += delta

winner = 'H' if scores[0] > scores[1] else 'A'
print(winner, fmt(ans[0]), fmt(ans[1]))
