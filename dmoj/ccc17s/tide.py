def main():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()

    half = (n + 1) // 2
    low = a[:half]
    high = a[half:]

    low.reverse()
    x = 0
    y = 0
    out = []
    while x < len(low) and y < len(high):
        out.append(low[x])
        out.append(high[y])
        x += 1
        y += 1

    if x < len(low):
        out.append(low[x])

    print(' '.join(map(str, out)))

main()
