def main():
    w, k = map(int, input().split())
    a = list(map(int, input().split()))
    a = [0] + a + [w]
    d = []
    for i in range(1, len(a)):
        d.append(a[i] - a[i - 1])

    all_sizes = set(d)
    for i, x in enumerate(d):
        s = x
        for j in range(i + 1, len(d)):
            s += d[j]
            all_sizes.add(s)

    all_sizes = list(all_sizes)
    all_sizes.sort()
    print(' '.join(str(x) for x in all_sizes))

main()
