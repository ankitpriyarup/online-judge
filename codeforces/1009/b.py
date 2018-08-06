s = input()
ones = 0
o = []
first_two = -1
for i, x in enumerate(s):
    if x == '0':
        o.append(x)
    elif x == '1':
        ones += 1
    else:
        if first_two == -1:
            first_two = len(o)
        o.append(x)

if first_two == -1:
    first_two = len(o)

one_str = '1' * ones
print(''.join(o[:first_two]) + one_str + ''.join(o[first_two:]))
