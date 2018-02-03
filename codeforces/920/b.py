from collections import deque
def main():
    n = int(input())
    intervals = []
    t = 1
    taken = [False] * 5003
    res = [0] * n
    for i in range(n):
        l, r = map(int, input().split())
        intervals.append((l, r))
        p = l
        while taken[p] and p < r:
            p += 1

        if not taken[p]:
            taken[p] = True
            res[i] = p

    print(' '.join(map(str, res)))

T = int(input())
for _ in range(T):
    main()
