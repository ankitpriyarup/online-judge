t = int(input())
for _ in range(t):
    s = input()
    s = ''.join(sorted(s))
    n = len(s)
    is_pal = all(s[i] == s[n - i - 1] for i in range(n))
    if is_pal:
        print(-1)
    else:
        print(s)
