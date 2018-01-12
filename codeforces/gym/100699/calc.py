n = int(raw_input())
res = [0]
for i in range(n):
    s = raw_input()
    if s == '+':
        res.append(res[-1] + 1)
    elif s == '-':
        res.append(res[-1] - 1)
    else:
        k = int(s[2:]) + 1
        res.append(res[-k])

print res[-1]
