from collections import Counter

def calc(h, i, j):
    ans = 100000
    for x, y in h:
        dx = x - i
        dy = y - j
        ans = min(ans, abs(dx) + abs(dy))
    return ans

r, c = map(int, input().split())
keys = [input() for _ in range(r)]
other = []
home = []

for i in range(r):
    for j in range(c):
        if keys[i][j] == 'O':
            other.append((i, j))
        elif keys[i][j] == 'H':
            home.append((i, j))

dist = [[calc(home, i, j) for j in range(c)] for i in range(r)]
print(dist)

all_dists = []
for i in range(r):
    for j in range(c):
        if keys[i][j] != '_':
            all_dists.append(dist[i][j])

all_dists.sort(reverse=True)

ans = 0
c = Counter(input()).most_common()
for k, v in c:
    if k == ' ':
        continue
    dd = all_dists.pop()
    # print('assigning', k, 'wiht freq', v, 'to key wiht dist', dd)
    ans += dd * v

print(ans)
