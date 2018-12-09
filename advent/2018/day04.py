from collections import *
import itertools
import random
import sys

def parse(line):
    if line.endswith('shift'):
        date, time, _, guard_id, _, _ = line.split()
        date = date[1:]
        time = time[:-1]
        return (date, time, guard_id)
    elif line.endswith('asleep'):
        date, time, _, _ = line.split()
        date = date[1:]
        time = time[:-1]
        return (date, time)
    elif line.endswith('up'):
        date, time, _, _ = line.split()
        date = date[1:]
        time = time[:-1]
        return (date, time)

def parse_datetime(date, time):
    year, mm, dd = map(int, date.split('-'))
    hh, mm = map(int, time.split(':'))
    return mm

def main():
    lines = [line.strip() for line in sys.stdin]
    lines = [parse(line) for line in lines]

    cur_id = -1
    start = -1
    asleep = False
    times_asleep = defaultdict(int)
    minutes_asleep = defaultdict(lambda: [0 for _ in range(60)])
    best = -1

    for line in lines:
        if len(line) == 3:
            start = 0
            asleep = False
            cur_id = int(line[-1][1:])
        else:
            cur = parse_datetime(*line[0:2])
            if not asleep:
                asleep = True
            else:
                for x in range(start, cur):
                    times_asleep[cur_id] += 1
                    minutes_asleep[cur_id][x] += 1
                asleep = False

                if best == -1 or times_asleep[cur_id] > times_asleep[best]:
                    best = cur_id

            start = cur

    print(times_asleep)
    print(minutes_asleep)

    guard_min = defaultdict(int)
    ans = -1
    for k, v in minutes_asleep.items():
        for x in range(60):
            guard_min[(k, x)] += v[x]
            ans = max(ans, guard_min[(k, x)])

    print(ans)
    for k, v in minutes_asleep.items():
        for x in range(60):
            if v[x] == ans:
                print(k, x)

main()
