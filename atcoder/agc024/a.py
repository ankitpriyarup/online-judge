CAP = 1000000000000000000

def main():
    a, b, c, k = map(int, input().split())
    if k % 2 == 0:
        print(a - b)
    else:
        print(b - a)

main()
