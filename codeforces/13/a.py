from math import gcd

def to_base(b, x):
    ans = 0
    while x > 0:
        ans += (x % b)
        x //= b

    return ans

def main():
    a = int(input())
    num, den = 0, 0
    for b in range(2, a):
        num += to_base(b, a)
        den += 1
    d = gcd(num, den)

    print('{}/{}'.format(num // d, den // d))

main()
