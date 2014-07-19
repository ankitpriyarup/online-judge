s = raw_input()
k = int(raw_input())
w = map(int, raw_input().split())
wmax = max(w)

ret = 0
for i, c in enumerate(s):
    ret += (i+1)*w[ord(c)-ord('a')]

for i in range(len(s)+1, len(s)+k+1):
    ret += i*wmax

print ret
