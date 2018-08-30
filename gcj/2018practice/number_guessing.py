import sys

def main():
    lo, hi = map(int, input().split())
    hi += 1
    n = int(input())
    while lo + 1 < hi:
        mid = (lo + hi) // 2
        print(mid)
        sys.stdout.flush()
        resp = input()
        if resp == 'WRONG_ANSWER':
            sys.exit(0)

        if resp == 'CORRECT':
            return
        elif resp == 'TOO_SMALL':
            lo = mid
        else:
            hi = mid

T = int(input())
for _ in range(T):
    main()
