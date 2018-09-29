k = int(input())
s = input()
used = [False for _ in range(26)]
starts = []
for i, c in enumerate(s):
    x = ord(c) - ord('a')
    if not used[x]:
        used[x] = True
        starts.append(i)

if len(starts) < k:
    print('NO')
else:
    print('YES')
    while len(starts) > k:
        starts.pop()
    for i in range(k - 1):
        print(s[starts[i]:starts[i + 1]])
    print(s[starts[-1]:])

