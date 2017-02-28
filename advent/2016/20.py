def c(a, b):
    if a[1] == b[1]:
        return a[0] < b[0]
    else:
        return a[1] < b[1]

def main():
    fin = open('20.in', 'r')
    # fin = open('20.samp', 'r')
    blocked = []
    for line in fin:
        start, end = map(int, line.strip().split('-'))

        blocked.append((start, end))

    blocked.sort(key=lambda x: x[0])
    for b in blocked:
        print(b)

    cur = (-1, -2)
    bad = 0
    for i in range(0, len(blocked)):
        x, y = blocked[i]
        if x - 1 <= cur[1]:
            cur = (cur[0], max(cur[1], y))
        else:
            print(cur, cur[1] - cur[0] + 1)
            bad += cur[1] - cur[0] + 1
            cur = (x, y)

    print(cur)
    bad += cur[1] - cur[0] + 1

    print(bad)
    print(4294967296 - bad)

main()
