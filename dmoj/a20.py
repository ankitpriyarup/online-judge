def myhex(x):
    s = hex(x)[2:]
    while len(s) < 8:
        s = '0' + s
    return s.upper()

n = int(input())
f = 1 << 20
for _ in range(n):
    b = int(input(), 16)
    if b & f:
        print(myhex(b ^ f), myhex(b))
    else:
        print(myhex(b))
