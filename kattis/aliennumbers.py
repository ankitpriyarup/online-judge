def read(num, src):
    base = len(src)
    ans = 0
    for c in num:
        ans *= base
        ans += src.index(c)

    return ans

def write(val, target):
    base = len(target)
    out = []
    while val:
        out.append(val % base)
        val //= base

    out = ''.join(target[c] for c in reversed(out))

    return out

def main(tt):
    num, src, target = input().split()
    val = read(num, src)
    ans = write(val, target)
    print('Case #{}: {}'.format(tt, ans))

T = int(input())
for tt in range(1, T + 1):
    main(tt)
