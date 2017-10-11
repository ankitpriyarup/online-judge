import sys

def ds(x):
    return sum(map(int, str(x)))

def solve(x):
    for p in range(11, 101):
        if ds(x) == ds(x * p):
            return p

    return 100

def main():
    for line in sys.stdin:
        x = int(line.strip())
        if x == 0:
            break

        print(solve(x))

main()
