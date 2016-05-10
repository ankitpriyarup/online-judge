from itertools import permutations

inp = [4, 8, 15, 16, 23, 42]
ans = 0
for l in range(1, 7):
    for p in permutations(inp, l):
        pp = list(map(str, list(p)))
        ans += int(''.join(pp))

print(ans)
