from math import gcd

T = int(input())
for tc in range(T):
    n = int(input())
    s = input()
    ans = ''.join('E' if x == 'S' else 'S' for x in s)
    print('Case #{}: {}'.format(tc + 1, ans))
