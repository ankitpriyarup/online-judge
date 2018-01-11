def digitsum(x):
    s = 0
    while x > 0:
        s += (x % 10)
        x //= 10

    return s

def main():
    ds = [digitsum(x) for x in range(1000)]
    n = input()
    ans = 6
    for i in range(1000000):
        if ds[i // 1000] == ds[i % 1000]:
            s = '{:06d}'.format(i)
            diff = sum(1 for i, c in enumerate(n) if c != s[i])
            ans = min(ans, diff)

    print(ans)

main()
