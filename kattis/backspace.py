s = input()
o = []
for c in s:
    if c == '<':
        if o:
            o.pop()
    else:
        o.append(c)
print(''.join(o))
