import sys

def main():
    options = []
    fin = open('15.in', 'r')
    for line in fin.readlines():
        line = line.strip()
        name_end = line.index(':')
        name = line[:name_end]
        raw_stats = line[(name_end + 2):].split(',')
        stats = [x.strip().split() for x in raw_stats]
        stats = dict((x[0], int(x[1])) for x in stats)
        options.append(stats)
    fin.close()

    ans1, ans2 = 0, 0
    for a in xrange(101):
        for b in xrange(101 - a):
            for c in xrange(101 - a - b):
                d = 100 - a - b - c

                stat = 'calories'
                total_cal = a * options[0][stat] + b * options[1][stat] + c * options[2][stat] + d * options[3][stat]

                cur = 1
                for stat in options[0]:
                    if stat == 'calories':
                        continue
                    cur *= a * options[0][stat] + b * options[1][stat] + c * options[2][stat] + d * options[3][stat]
                    if cur < 0:
                        cur = 0
                        break

                if total_cal == 500:
                    ans2 = max(ans2, cur)

                ans1 = max(ans1, cur)

    print "Part 1", ans1
    print "Part 2", ans2

if __name__ == '__main__':
    main()
