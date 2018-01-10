def main():
    a, b = map(int, input().split())
    x, y, z = map(int, input().split())
    na = 2 * x + y
    nb = y + 3 * z
    ans = max(0, na - a) + max(0, nb - b)
    print(ans)

main()
