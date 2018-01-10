import sys

sys.setrecursionlimit(500000)

def main():
    n, a, b, c = map(int, raw_input().split())
    print solve(n, a, b, c, {})

def solve(n, a, b, c, m):
    if n < 0:
        return float('-inf')
    if n == 0:
        return 0

    if n not in m:
        ans = 1 + max(solve(n - a, a, b, c, m), solve(n - b, a, b, c, m), solve(n - c, a, b, c, m))
        m[n] = ans

    return m[n]

main()
