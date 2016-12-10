import functools
from collections import defaultdict

def main():
    fin = open('10.in', 'r')
    #fin = open('10.samp', 'r')

    lows = {}
    highs = {}
    bots = {k: list() for k in range(2000)}
    outputs = [-1] * 21

    for line in fin:
        command = line.strip().split()
        if command[0] == 'bot':
            bot_num = int(command[1])

            low_type = command[5]
            low = int(command[6])

            hi_type = command[-2]
            hi = int(command[-1])

            lows[bot_num] = (low_type, low)
            highs[bot_num] = (hi_type, hi)
        else:
            value = int(command[1])
            bot = int(command[-1])
            bots[bot].append(value)

    while any(x == -1 for x in outputs):
        for bot in bots:
            if len(bots[bot]) >= 2:
                lo = min(bots[bot])
                hi = max(bots[bot])

                if lo == 17 and hi == 61:
                    # Part 1
                    print('PART1', bot)

                if lows[bot][0] == 'output':
                    outputs[lows[bot][1]] = lo
                else:
                    bots[lows[bot][1]].append(lo)

                if highs[bot][0] == 'output':
                    outputs[highs[bot][1]] = hi
                else:
                    bots[highs[bot][1]].append(hi)

                bots[bot] = list()

    # Part 2:
    print('PART2', functools.reduce(lambda x, y: x * y, outputs[:3]))

main()
