def main():
    n = int(input())
    m = int(input())
    if n <= 30:
        print(m % (1 << n))
    else:
        print(m)

if __name__ == '__main__':
    main()
