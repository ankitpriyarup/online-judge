def main():
    n, m = map(int, input().split())
    print((n - 1) * (m - 1))

T = int(input())
for _ in range(T):
    main()
