n, m = map(int, input().split())
s = input()
t = input()

if '*' in s:
    x = s.index('*')
    if t[:x] == s[:x] and t[x:].endswith(s[x+1:]):
        print('YES')
    else:
        print('NO')
else:
    print('YES' if s == t else 'NO')
