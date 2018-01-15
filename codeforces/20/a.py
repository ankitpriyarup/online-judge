s = input()
o = []
for c in s:
    if c == '/' and o and o[-1] == '/':
        continue
    o.append(c)

res = ''.join(o)

if len(res) > 1 and res[-1] == '/':
    print(res[:-1])
else:
    print(res)
