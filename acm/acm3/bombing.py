T = int(raw_input())
for case_num in xrange(T):
    C, N, M = map(int, raw_input().split())
    camps = []

    for i in xrange(C):
        x, y, p = map(int, raw_input().split())
        camps.append((i, x, y, p))

    byx = sorted(camps, key=lambda x: x[1])
    q = []
    best  = 0
    for e in byx:
        q.append(e[0])
        while e[1] - camps[q[0]][1] > N:
            q = q[1:]

        byy = []
        for x in q:
            byy.append(camps[x])

        byy = sorted(byy, key=lambda x: x[2])
        q2 = []
        cur = 0

        for f in byy:
            q2.append(f[0])
            cur += f[3]
            while f[2] - camps[q2[0]][2] > M:
                cur -= camps[q2[0]][3]
                q2 = q2[1:]
            best = max(best, cur)

    print best
