from __future__ import division, print_function
p, pa, pb = map(lambda s: int(s.replace('.', '')), raw_input().split())

printed = False
for x in range(10000000):
    rem = p - x * pa
    if rem >= 0 and rem % pb == 0:
        printed = True
        print(x, rem // pb)

if not printed:
    print('none')
