from collections import defaultdict
import sys
import itertools

def main():
    table = defaultdict(lambda: defaultdict())
    people_set = set()
    fin = open('13.in', 'r')
    for line in fin.readlines():
        words = line.strip().split()
        p1 = words[0]
        p2 = words[-1][:-1]
        difference = (-1 if words[2] == "lose" else 1) * int(words[3])
        table[p1][p2] = difference
        people_set.add(p1)

    people = list(people_set)
    head = people[0]
    best = -100000 
    for perm in itertools.permutations(people[1:]):
        cur = table[head][perm[0]] + table[head][perm[-1]]
        cur += table[perm[0]][head] + table[perm[0]][perm[1]]
        cur += table[perm[-1]][head] + table[perm[-1]][perm[-2]]
        for i in xrange(1, len(perm) - 1):
            cur += table[perm[i]][perm[i - 1]] + table[perm[i]][perm[i + 1]]

        best = max(best, cur)

    print "Part 1", best

    for person in people:
        table[person]["Me"] = 0
        table["Me"][person] = 0

    head = "Me"
    best = -100000 
    for perm in itertools.permutations(people):
        cur = table[head][perm[0]] + table[head][perm[-1]]
        cur += table[perm[0]][head] + table[perm[0]][perm[1]]
        cur += table[perm[-1]][head] + table[perm[-1]][perm[-2]]
        for i in xrange(1, len(perm) - 1):
            cur += table[perm[i]][perm[i - 1]] + table[perm[i]][perm[i + 1]]

        best = max(best, cur)

    print "Part 2", best

if __name__ == '__main__':
    main()
