from math import ceil

def main():
    n, m, a = map(int, input().split())

    w = int(ceil(n / a))
    h = int(ceil(m / a))

    print(w * h)
    
main()
