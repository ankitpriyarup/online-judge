c, n = map(int, input().split())
poss = True
cur = 0

for _ in range(n):
    left, on, stayed = map(int, input().split())

    cur -= left
    if cur < 0:
        poss = False

    cur += on
    if cur > c:
        poss = False

    if stayed > 0 and cur != c:
        poss = False

poss = poss and (cur == 0)
print(('' if poss else 'im') + 'possible')
