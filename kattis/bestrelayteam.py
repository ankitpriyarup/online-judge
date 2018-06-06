def main():
    n = int(input())
    aa = []
    bb = []
    for _ in range(n):
        name, a, b = input().split()
        a, b = map(float, [a, b])
        aa.append((a, name))
        bb.append((b, name))

    aa.sort()
    bb.sort()

    best = []
    best_time = float('inf')
    for a, name in aa:
        cur = [name]
        bptr = 0
        cur_time = a
        while len(cur) < 4:
            if bb[bptr][1] not in cur:
                cur_time += bb[bptr][0]
                cur.append(bb[bptr][1])
            bptr += 1

        if cur_time < best_time:
            best_time, best = cur_time, cur
    print('{:.09f}'.format(best_time))
    for name in best:
        print(name)

main()
