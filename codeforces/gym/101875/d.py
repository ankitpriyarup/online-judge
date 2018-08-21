def brute(n, d):
    ans = sum(1 for x in range(1, n + 1) if x >= d and x % 2 == d % 2)
    return ans

def smart(n, d):
    if n % 2 != d % 2:
        n -= 1

    if d % 2 == 1:
        d += 1
        n += 1

    return max(0, n // 2 - (d - 1) // 2) - int(d == 0)

def main():
    n, x1, y1, x2, y2 = map(int, input().split())
    d = abs(x1 - x2) + abs(y1 - y2)
    print(smart(n, d))

main()
