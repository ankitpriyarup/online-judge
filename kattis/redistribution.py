from collections import deque
n = int(input())
a = [(x, i) for i, x in enumerate(map(int, input().split()))]
a.sort(reverse=True)
dq = deque()
for _ in range(a[0][0]):
    dq.append(a[0][1])

works = True
for i in range(1, n):
    if not works:
        break
    for _ in range(a[i][0]):
        if not dq:
            works = False
            break
        idx = dq.popleft()
        if a[i][1] == idx:
            works = False
            break
    for _ in range(a[i][0]):
        dq.append(a[i][1])

for _ in range(a[0][0]):
    if not dq:
        works = False
        break
    idx = dq.popleft()
    if a[0][1] == idx:
        works = False
        break

if works:
    print(' '.join(str(i + 1) for x, i in a))
else:
    print('impossible')
