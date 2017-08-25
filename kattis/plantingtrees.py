def main():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    a.reverse()

    ans = 0
    for i, x in enumerate(a):
        ans = max(ans, i + x + 1)

    print(ans + 1)

main()
