n = int(input())
d = {}
for _ in range(n):
    s = input()
    if s in d:
        v = d[s] + 1
        d[s] = v
        print(s + str(v))
    else:
        print('OK')
        d[s] = 0
