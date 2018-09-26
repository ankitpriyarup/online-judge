s = input()
s = s[1:-1]
if not s:
    print(0)
else:
    s = set(s.split(', '))
    print(len(s))
