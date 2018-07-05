from fractions import Fraction

def from_cont(a):
    res = Fraction(a.pop())
    while a:
        res = 1 / res
        res = res + a.pop()

    return res

def to_cont(a):
    res = []
    while a > 0:
        res.append(int(a))
        a -= int(a)
        if a > 0:
            a = 1 / a

    return ' '.join(map(str, res))

def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    aa = from_cont(a)
    bb = from_cont(b)

    print(to_cont(aa + bb))
    print(to_cont(aa - bb))
    print(to_cont(aa * bb))
    print(to_cont(aa / bb))

main()
