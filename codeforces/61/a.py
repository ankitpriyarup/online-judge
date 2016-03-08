a = input()
b = input()
out = []

for i, c in enumerate(a):
    d = b[i]
    if c == d:
        out.append('0')
    else:
        out.append('1')

print(''.join(out))
