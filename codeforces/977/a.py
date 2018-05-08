a, b = input().split()
a = list(a)
b = int(b)
for _ in range(b):
    if a[-1] == '0':
        a.pop()
    else:
        a[-1] = str(int(a[-1]) - 1)
    if not a:
        a = ['0']
print(''.join(a))
