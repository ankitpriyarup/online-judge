import sys
def count(n, options, takes):
    if n == 0:
        return 1
    if n < 0 or options == [] or takes <= 0:
        return 0

    return count(n - options[-1], options[:-1], takes - 1) +  count(n, options[:-1], takes)


def main():
    denoms = []
    for line in sys.stdin:
        denoms.append(int(line))
    denoms.sort()

    for t in xrange(1, 100):
        if count(150, denoms, t) > 0:
            print t
            break

if __name__ == '__main__':
    main()
