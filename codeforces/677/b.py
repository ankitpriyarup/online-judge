from math import ceil

n, h, k = map(int, input().split())
a = list(map(int, input().split()))
cur_h = 0
cur_t = 0

for x in a:
    if cur_h + x <= h:
        cur_h += x
    else:
        # figure out some time
        num = x + cur_h - h
        t = num // k
        if num % k != 0:
            t += 1
        cur_t += t
        cur_h = max(0, cur_h - k * t) + x

print(cur_t + int(ceil(cur_h / k)))
