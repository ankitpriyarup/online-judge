import sys

def main():
    for line in sys.stdin.readlines():
        a, b = map(int, line.strip().split())
        print(abs(a - b))

main()
