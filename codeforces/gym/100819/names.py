def main():
    n = int(input())
    names = [input().split() for _ in range(n)]

    names.sort(key=lambda x: (x[1], x[0]))
    for f, l in names:
        print(f, l)

main()
