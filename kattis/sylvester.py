def val(n, i, j):
    assert 0 <= i < n
    assert 0 <= j < n
    if n <= 2:
        return -1 if i == 1 and j == 1 else 1
    half = n >> 1
    if i >= half and j >= half:
        return -val(half, i - half, j - half)
    else:
        return val(half, i % half, j % half)

T = int(input())
for _ in range(T):
    n, x, y, w, h = map(int, input().split())
    out = [[val(n, i, j) for j in range(x, x + w)] for i in range(y, y + h)]
    for row in out:
        print(' '.join(map(str, row)))
    print()
