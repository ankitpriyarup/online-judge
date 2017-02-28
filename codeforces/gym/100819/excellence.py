def main():
    n = int(input())
    s = [int(input()) for _ in range(n)]

    s.sort()
    start = 0
    end = n - 1
    ans = float('inf')

    while start < end:
        ans = min(ans, s[start] + s[end])
        start += 1
        end -= 1

    print(ans)

main()
