from collections import defaultdict, deque, Counter
import itertools
import math
import sys

def print_court(start, sideline):
    print(start[3], start[4], start[5])
    print(start[2], start[1], start[0])

    print('side', sideline)

def main():
    n = int(input())
    setter = input()
    start = list(input().split())

    while start[0] != setter:
        start = start[1:] + [start[0]]

    start = [start[0]] + list(reversed(start[1:]))

    sideline = list(input().split())
    sideline = sideline[1:]

    # print_court(start, sideline)
    for _ in range(n):
        if start[-1] == setter:
            start = [start[-1]] + start[:-1]
        else:
            sideline.append(start[-1])
            start = [sideline[0]] + start[:-1]
            sideline = sideline[1:]
            # print_court(start, sideline)

    tail = start[1:]
    tail = list(reversed(tail))
    start = [start[0]] + tail
    print(' '.join(start))


main()
