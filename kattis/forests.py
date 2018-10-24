import sys

p, t = map(int, sys.stdin.readline().split())
f = [[False for _ in range(t)] for _ in range(p)]
for line in sys.stdin:
    person, tree = map(int, line.strip().split())
    person -= 1
    tree -= 1
    f[person][tree] = True

f = set(tuple(r) for r in f)
print(len(f))
