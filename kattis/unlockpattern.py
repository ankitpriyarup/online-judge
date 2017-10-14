import math
def dist(a, b):
    xd = a[0] - b[0]
    yd = a[1] - b[1]
    return math.sqrt(xd**2 + yd**2)

def main():
    a = [list(map(int, input().split())) for _ in range(3)]
    pos = []
    for v in range(1, 10):
        for i in range(3):
            for j in range(3):
                if a[i][j] == v:
                    pos.append((i, j))

    ans = 0.0
    for i in range(1, 9):
        ans += dist(pos[i - 1], pos[i])

    print(ans)

main()
