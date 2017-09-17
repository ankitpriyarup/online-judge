def clash(a, b):
    return a[0] == b[0] or a[1] == b[1] or a[0] + a[1] == b[0] + b[1] or a[0] - a[1] == b[0] - b[1]

def main():
    n = int(input())
    points = [tuple(map(int, input().split())) for _ in range(n)]

    good = True
    for i in range(n):
        for j in range(i + 1, n):
            if clash(points[i], points[j]):
                good = False
                break

        if not good:
            break

    print('CORRECT' if good else 'INCORRECT')

main()
