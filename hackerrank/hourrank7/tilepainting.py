def main():
    N = int(input())
    s = input()
    ans = 1
    for i in range(1, N):
        if s[i] != s[i - 1]:
            ans += 1

    print(ans)

main()
