import itertools
import sys

def get_dist(db, a, b):
    key1 = a + '.' + b
    key2 = b + '.' + a
    if key1 in db:
        return db[key1]
    else:
        return db[key2]

def main():
    places = set()
    db = {}

    fin = open('9.in', 'r')
    for line in fin.readlines():
        tokens = [x.strip() for x in line.strip().split()]
        loc_a = tokens[0]
        loc_b = tokens[2]
        dist  = int(tokens[4])
        
        places.add(loc_a)
        places.add(loc_b)
        db[loc_a + '.' + loc_b] = dist
        db[loc_b + '.' + loc_a] = dist
    fin.close()

    places = list(places)
    num_places = len(places)
    shortest = 100000000000000
    longest = 0
    for perm in itertools.permutations(places):
        cur = 0
        for i in xrange(1, num_places):
            cur += get_dist(db, perm[i], perm[i - 1])

        shortest = min(shortest, cur)
        longest = max(longest, cur)

    print "Part 1", shortest
    print "Part 2", longest


if __name__ == '__main__':
    main()
