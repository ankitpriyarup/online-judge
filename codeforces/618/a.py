n = int(raw_input())
s = [1]
for _ in xrange(n - 1):
    while len(s) >= 2 and s[-1] == s[-2]:
        s.pop()
        b = s.pop()
        s.append(b + 1)

    s.append(1)


while len(s) >= 2 and s[-1] == s[-2]:
    s.pop()
    b = s.pop()
    s.append(b + 1)

print ' '.join(map(str, s))
