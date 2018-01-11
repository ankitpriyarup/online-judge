def main():
    n = int(input())
    for x in range(2, n + 4):
        if n % x != 0:
            print(x)
            return

main()
