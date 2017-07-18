def main():
    s = input()
    s = s.replace('=', '')
    last = ''
    l = 0
    ans = 0
    for c in s:
        if c == last:
            l += 1
        else:
            ans = max(ans, l)
            l = 1

        last = c

    print(1 + max(ans, l))

T = int(input())
for _ in range(T):
    main()
