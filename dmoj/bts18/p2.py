s = input()
n = len(s)
hist = [[0 for _ in range(n + 1)] for _ in range(26)]
for i in range(1, n + 1):
    for j in range(26):
        hist[j][i] = hist[j][i - 1]
    if s[i - 1] == ' ':
        continue
    hist[ord(s[i - 1]) - ord('a')][i] += 1

T = int(input())
for _ in range(T):
    l, r, c = input().split()
    l, r = map(int, (l, r))
    x = ord(c) - ord('a')
    print(hist[x][r] - hist[x][l - 1])
    
