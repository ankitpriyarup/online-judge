from collections import defaultdict

def main():
    n = int(input())

    p = []
    for _ in range(n):
        x, y = map(int, input().split())
        p.append((x, y))

    d = defaultdict(int)
    for i in range(n):
        for j in range(i + 1, n):
            x1, y1 = p[i]
            x2, y2 = p[j]

            center = (x1 + x2, y1 + y2)
            radius = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
            d[(center, radius)] += 1

    ans = 0
    for _, v in d.items():
        ans += v * (v - 1) // 2

    print(ans)

main()
