l, x = map(int, input().split())
cur = 0
banned = 0
for _ in range(x):
    w, p = input().split()
    p = int(p)
    if w == 'enter':
        if cur + p > l:
            banned += 1
        else:
            cur += p
    else:
        cur -= p

print(banned)
