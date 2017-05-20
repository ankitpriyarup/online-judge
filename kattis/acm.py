from collections import defaultdict
import sys

def main():
    scores = defaultdict(int)
    for line in sys.stdin.readlines():
        line = line.strip()
        if line == '-1':
            break

        time, problem, verdict = line.split()
        time = int(time)
        if verdict == 'wrong':
            scores[problem] -= 1
        else:
            scores[problem] = -20 * scores[problem] + time

    correct = sum(1 for k, v in scores.items() if v >= 0)
    time = sum(v for k, v in scores.items() if v >= 0)

    print(correct, time)


main()
