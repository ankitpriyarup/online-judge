def main():
    num_cases = int(input())
    for _ in range(num_cases):
        n = int(input())
        a = list(map(int, input().split()))
        a.sort()

        s = 0
        e = n -1
        ans = 0

        while s < e:
            ans += a[e] - a[s]
            s += 1
            e -= 1

        print(ans)

main()
