def main():
    a, b = map(int, input().split())
    x = b - a
    h = x * (x + 1) // 2
    print(h - b)

main()
