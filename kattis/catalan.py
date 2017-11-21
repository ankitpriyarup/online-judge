def main():
    MAXN = 5003
    c = [1 for _ in range(MAXN)]
    for i in range(MAXN - 1):
        c[i + 1] = c[i] * 2 * (2 * i + 1) // (i + 2)

    q = int(input())
    for _ in range(q):
        x = int(input())
        print(c[x])

main()
