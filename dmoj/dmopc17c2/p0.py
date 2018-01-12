def d2(x, y):
    return x * x + y * y

def main():
    x1, y1 = map(int, input().split())
    x2, y2 = map(int, input().split())
    xs, ys = map(int, input().split())
    d = int(input())
    shady = d2(x1 - xs, y1 - ys) <= d * d or d2(x2 - xs, y2 - ys) <= d * d
    print('Yes' if shady else 'No')


main()
