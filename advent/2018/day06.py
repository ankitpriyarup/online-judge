import sys

def main():
    lines = [line.strip().split(', ') for line in sys.stdin]
    pts = []
    for line in lines:
        x, y = map(int, line)
        pts.append((x, y))

    BOUND = 1000
    ans = 0
    for x in range(-BOUND, BOUND):
        for y in range(-BOUND, BOUND):
            cost = sum(abs(x - px) + abs(y - py) for px, py in pts)
            if cost < 10000:
                ans += 1

    print(ans)

main()
