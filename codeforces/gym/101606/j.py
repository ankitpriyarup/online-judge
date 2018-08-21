n = int(raw_input())
arr = map(int, raw_input().split())

m = {0: 2, 1: 1, 2: 0.5, 4: 1.0 / 4, 8: 1.0 / 8, 16: 1.0 / 16}

tot = 0
for x in arr:
    tot += m[x]

print tot
