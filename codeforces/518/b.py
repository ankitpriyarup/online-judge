from collections import Counter

s = input()
t = input()

sc = Counter(s)
tc = Counter(t)

FLIP_CASE = ord('a') - ord('A')

yay, whoops = 0, 0
for c in s:
    amount = min(sc[c], tc[c])
    if amount > 0:
        yay += amount
        tc[c] -= amount
        sc[c] -= amount

for c in sc:
    fc = chr(FLIP_CASE ^ ord(c))
    amount = min(sc[c], tc[fc])
    if amount > 0:
        whoops += amount
        tc[fc] -= amount

print(yay, whoops)
