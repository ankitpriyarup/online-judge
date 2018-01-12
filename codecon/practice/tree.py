import sys
from collections import deque

def dfs(tree, knights, ids, node):
    for child in tree[node]:
        dfs(tree, knights, ids, child)

    best_child = None
    for child in tree[node]:
        if knights[ids[child]] - 3 >= knights[node]:
            if best_child is None or knights[ids[child]] > knights[ids[best_child]] \
                or (knights[ids[child]] == knights[ids[best_child]] and ids[child] < ids[best_child]):
                best_child = child

    if best_child is not None:
        ids[node], ids[best_child] = ids[best_child], ids[node]

n = int(input())

tree = {}
knights = {}
names = set()

for _ in range(n):
    line = input().split()
    name, k, c = line[0:3]
    k, c = int(k), int(c)
    tree[name] = line[3:]
    knights[name] = k
    names.add(name)
    
root = [name for name in names if all(name not in tree[name2] for name2 in names)][0]
ids = {name: name for name in names}
dfs(tree, knights, ids, root)

q = [root]
while q:
    out = sorted(ids[x] for x in q)
    print(' '.join(out))

    new_q = []
    for node in q:
        for child in tree[node]:
            new_q.append(child)

    q = new_q
