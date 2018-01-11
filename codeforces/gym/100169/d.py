n = int(raw_input())
courses = {}
for i in range(n):
    first, last, cid = raw_input().split(' ')
    join = first + "_" + last
    if not cid in courses:
        courses[cid] = set()
    courses[cid].add(join)
print '\n'.join(map(lambda x: "" + x + " " + str(len(courses[x])), sorted(courses)))
