n, k = map(int, input().split())
pkmn = []
for i in range(n):
    a, d, s = map(int, input().split())
    pkmn.append((a, d, s, i))

pkmn.sort(reverse=True)
ids = set(p[3] for p in pkmn[:k])
pkmn.sort(key=lambda p: p[1], reverse=True)
ids |= set(p[3] for p in pkmn[:k])
pkmn.sort(key=lambda p: p[2], reverse=True)
ids |= set(p[3] for p in pkmn[:k])

print(len(ids))
