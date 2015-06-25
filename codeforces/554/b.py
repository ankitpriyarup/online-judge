n = int(raw_input())
freq_map = {}
for i in xrange(n):
    row = raw_input()
    if row in freq_map:
        freq_map[row] += 1
    else:
        freq_map[row] = 1

ans = 0
for k in freq_map:
    ans = max(ans, freq_map[k])

print ans
