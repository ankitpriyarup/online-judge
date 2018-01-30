alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ '"
pi = 3.1415926535
def main():
    s = input()
    n = len(s)
    ans = 0
    for i in range(1, n):
        x = alpha.index(s[i - 1])
        y = alpha.index(s[i])
        dist = min((y - x + 28) % 28, (x - y + 28) % 28)
        ans += dist

    ans *= pi * 60.0 / 28.0
    ans /= 15.0
    ans += n
    print(ans)

T = int(input())
for _ in range(T):
    main()
