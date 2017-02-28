from collections import deque

def main():
    fin = open('15.in', 'r')
    # fin = open('15.samp', 'r')
    discs = []
    i = 1
    for line in fin:
        words = line.strip().split()
        total = int(words[3])
        start = int(words[-1][:-1])
        discs.append((i, total, start))

        i += 1

    for x in range(1000000000):
        if all((i + x + start) % total == 0 for i, total, start in discs):
            print(x)
            break

main()
