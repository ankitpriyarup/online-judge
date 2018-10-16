def dig_sum(x):
    ret = 0
    while x > 0:
        ret += x % 10
        x //= 10
    return ret

n = input()
ans = dig_sum(int(n))
for l in range(len(n)):
    suff = int(n[l:])
    a = suff + 1
    b = int(n) - suff - 1
    if a >= 0 and b >= 0:
        ans = max(ans, dig_sum(a) + dig_sum(b))


print(ans)
