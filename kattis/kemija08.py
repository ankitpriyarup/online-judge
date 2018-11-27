def fix(s):
    o = []
    i = 0
    n = len(s)
    while i < n:
        o.append(s[i])
        if s[i] in 'aeiou':
            i += 3
        else:
            i += 1

    return ''.join(o)

s = input().split()
out = [fix(word) for word in s]
print(' '.join(out))
