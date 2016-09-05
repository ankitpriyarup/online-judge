import itertools
def tobase(n):
    if n == 0:
        return 1

    l = 0
    while n > 0:
        l += 1
        n //= 7

    return l

def main():
    n, m = map(int, input().split())
    nlen = tobase(n - 1)
    mlen = tobase(m - 1)
    places = nlen + mlen

    ans = 0
    for perm in itertools.permutations('0123456', places):
        hour = ''.join(perm[:nlen])
        minute = ''.join(perm[nlen:])
        if int(hour, 7) < n and int(minute, 7) < m:
            ans += 1

    print(ans)

main()
