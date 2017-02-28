flip = {'R': 'S', 'B':'K', 'L': 'H'}
s = input()
out = []
i = 0
n = len(s)
while i < n:
    if i + 3 <= n:
        chunk = s[i:(i + 3)]
        if chunk[0] != chunk[1] and chunk[1] != chunk[2] and chunk[0] != chunk[2]:
            out.append('C')
            i += 3
        else:
            out.append(flip[s[i]])
            i += 1
    else:
        out.append(flip[s[i]])
        i += 1

print(''.join(out))
