n = int(raw_input())
a = map(int, raw_input().split())
freq = [0] * 7000
for b in a:
    freq[b] += 1

ans = 0
for i in xrange(6500):
    if freq[i] > 1:
        ans += freq[i] - 1
        freq[i + 1] += (freq[i] - 1)
        freq[i] = 1

print ans
