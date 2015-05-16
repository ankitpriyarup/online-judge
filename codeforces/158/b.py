n = int(raw_input())
s = map(int, raw_input().split())
freq_map = [0]*4
for v in s:
    freq_map[v - 1] += 1

ans = freq_map[3]
ans += freq_map[2]
freq_map[0] -= freq_map[2]
ans += (freq_map[1] + 1) / 2
freq_map[0] -= 2 if freq_map[1] % 2 == 1 else 0
freq_map[0] = max(freq_map[0], 0)
ans += (freq_map[0] + 3) / 4

print ans
