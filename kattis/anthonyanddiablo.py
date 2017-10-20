import math

def main():
    a, n = map(float, input().split())
    # a = pi * r^2
    # r = sqrt(a / pi)
    # c = 2 * pi * sqrt(a / pi)
    circ = 2.0 * math.sqrt(math.pi * a)
    if circ <= n:
        print('Diablo is happy!')
    else:
        print('Need more materials!')

main()
