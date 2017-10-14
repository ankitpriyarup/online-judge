import math

def main():
    x, lo, hi = map(int, input().split())
    a = float('inf')
    b = float('-inf')
    for i in range(10):
        if lo <= math.ceil(x) <= hi:
            a = min(a, i)
            b = max(b, i)

        x = 10.0 * math.sqrt(x)

    if a == float('inf') and b == float('-inf'):
        print('impossible')
    elif math.ceil(x) <= hi:
        print('{} inf'.format(a))
    else:
        print('{} {}'.format(a, b))

main()
