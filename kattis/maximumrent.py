def valid(m, s, x, y):
    return (x >= 1) and (y >= 1) and (x + y <= m) and (2 * x + y >= s)

def main():
    a, b = map(int, input().split())
    m, s = map(int, input().split())
    # intersections of all lines
    # x = 1, y = 1, x + y = m, 2x + y = s
    opts = [(1, 1), (1, m - 1), (m - 1, 1), (1, s - 2), ((s - 1) / 2, 1), (s - m, 2 * m - s)]
    ans = float('-inf')
    for x, y in opts:
        if valid(m, s, x, y):
            score = a * x + b * y
            ans = max(ans, score)

    print(ans)

main()
