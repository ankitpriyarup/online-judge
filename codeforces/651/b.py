n = int(input())
a = list(map(int, input().split()))
freq = {}
table = [0] * 1001

for x in a:
    if x in freq:
        freq[x] += 1
        table[freq[x]] += 1
    else:
        freq[x] = 1
        table[1] += 1

ans = 0
for x in table:
    if x >= 2:
        ans += x - 1

print(ans)
