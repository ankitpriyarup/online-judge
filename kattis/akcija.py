def main():
    n = int(input())
    a = [int(input()) for _ in range(n)]
    a.sort(reverse=True)
    ans = sum(a)
    for i in range(2, len(a), 3):
        ans -= a[i]
    print(ans)

main()
