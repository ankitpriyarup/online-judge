def main():
    n, k, x = map(int, input().split())
    a = list(map(int, input().split()))
    end = n - k
    ans = sum(a[:end]) + x * k

    print(ans)

main()
