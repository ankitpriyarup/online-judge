def main():
    c = float(input())
    l = int(input())
    area = 0.0
    for _ in range(l):
        x, y = map(float, input().split())
        area += x * y

    print(area * c)

main()
