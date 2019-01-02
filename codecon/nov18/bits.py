def count(s):
    ans = 0
    for i in range(32):
        for j in range(i + 1, 33):
            t = s[i:j]
            if sum(x == '1' for x in t) == j - i:
                ans = max(ans, j - i)

    return ans

s = input()
ans = count(s)
for i in range(32):
    if s[i] == '0':
        t = s[:i] + '1' + s[i + 1:]
        ans = max(ans, count(t))

print(ans)
