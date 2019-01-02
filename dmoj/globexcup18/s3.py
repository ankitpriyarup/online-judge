# 1. if the bit is enabled, choose an odd number. Else, choose an even number
#
# 0 / 1: 1, 1 / 1: 1
# (0+2)/2: 2, 1/2: 2
# (0+2)/3: 4, (1+3)/3, 4
#
# regardless, 2^(n - 1) for each bit
# xor answer is always (2^(n - 1))^k
#
# || answer is
# if 0, then 1 option
# otherwise 2^n - 1
#
# (2^n - 1)^(bitcount)
#
# && answer is
# if 1 then 1 option
# otherwise 2^n - 1
#
# (2^n - 1)^(k - bitcount)

n, m, k, v = map(int, input().split())
x = pow(2, n - 1, m)
x = pow(x, k, m)
print(x)

pc = 0
for i in range(k):
    if v & (1 << i):
        pc += 1

base = pow(2, n, m) - 1
if base < 0:
    base += m
y = pow(base, pc, m)
print(y)
z = pow(base, k - pc, m)
print(z)
