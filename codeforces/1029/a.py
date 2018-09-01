n, k = map(int, input().split())
s = input()
for pref_len in range(1, n + 1):
    if (s[:pref_len] + s).startswith(s):
        t = s[:pref_len]
        break

print(t * (k - 1) + s)
