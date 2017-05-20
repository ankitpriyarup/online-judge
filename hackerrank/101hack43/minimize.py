def calc(a):
    ans = 0
    for x in a:
        for y in a:
            ans += (x - y) * (x - y)

    return ans // 2

def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    for i in range(n - k + 1):
        part = a[i:(i + k)]
        error = calc(part)
        print(i + k - 1, error, sum(part))

main()
