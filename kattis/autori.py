s = input()
out = [s[0]]
n = len(s)
for i in range(1, n - 1):
    if s[i] == '-':
        out.append(s[i + 1])
print(''.join(out))
