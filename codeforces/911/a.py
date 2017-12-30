def main():
    n = int(input())
    a = list(map(int, input().split()))
    m = min(a)
    xs = [i for i, x in enumerate(a) if x == m]
    ans = min(b - a for a, b in zip(xs, xs[1:]))

    print(ans)

main()
