n = input()
m = input()

a, b = len(n), len(m) - 1
if b > a:
    n = '0' * (a + b) + n

ret = n[:-b] + '.' + n[-b:]
ret = ret.strip('0')
if ret[0] == '.':
    print('0', end='')

if ret[-1] == '.':
    print(ret[:-1])
else:
    print(ret)
