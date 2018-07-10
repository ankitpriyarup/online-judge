s = input()
w = int(input())
n = len(s)
t = []
for p in range(0, n, w):
    t.append(s[p])

print(''.join(t))

