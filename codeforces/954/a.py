n = int(input())
s = input()
ans = 0
out = []
for c in s:
    if out and out[-1] != 'D' and out[-1] != c:
        out.pop()
        out.append('D')
    else:
        out.append(c)
print(len(out))
