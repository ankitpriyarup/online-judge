def dist(x0, y0, x1, y1):
    return abs(x0 - x1) + abs(y0 - y1)

def main():
    x0, y0 = map(int, input().split())
    n = int(input())
    k = 0
    for _ in range(n):
        x, y = map(int, input().split())
        k = max(k, dist(x0, y0, x, y))

    print(2 * k * k)

main()
