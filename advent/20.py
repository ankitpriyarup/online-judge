from math import sqrt
from heapq import heappush, heappop

def score(x):
    if x == 1:
        return 10

    ans = 1 + x
    for i in xrange(2, int(sqrt(x)) + 1):
        if i >= x:
            break

        if x % i == 0:
            ans += i

            if i * i != x:
                ans += x / i

    return 10 * ans

def ans1():
    target = 34000000
    cap = target / 10 + 2

    arr = [0] * cap
    for i in xrange(1, cap):
        for j in xrange(i, cap, i):
            arr[j] += 10 * i
        if arr[i] > target:
            print i
            break

def main():
    target = 34000000
    cap = target / 10 + 2

    arr = [0] * cap
    best_ans = 1
    best_score = 10
    for i in xrange(1, cap):
        for j in xrange(i, min(cap, 50 * i), i):
            arr[j] += 11 * i

        if arr[i] > target:
            print i
            break

if __name__ == '__main__':
    main()
