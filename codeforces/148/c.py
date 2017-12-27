def main():
    n, a, b = map(int, input().split())
    if n == 1:
        print(1)
        return

    if b == 0 and a == n - 1:
        print(-1)
        return

    if b == 0:
        ret = [2, 1]
    else:
        ret = [1]

    s = sum(ret)
    for _ in range(b):
        ret.append(s + 1)
        s += ret[-1]

    best = max(ret)
    for _ in range(a):
        ret.append(best + 1)
        best += 1

    if len(ret) > n or any(x > 50000 for x in ret):
        print(-1)
        return

    while len(ret) < n:
        ret.append(1)

    assert(all(1 <= x <= 50000 for x in ret))
    assert(len(ret) == n)

    print(' '.join(str(x) for x in ret))

main()
