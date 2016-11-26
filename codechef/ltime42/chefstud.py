def flip(c):
    if c == '<':
        return '>'
    elif c == '>':
        return '<'
    else:
        return c

t = int(input())
for _ in range(t):
    s = input()
    n = len(s)
    s = [flip(c) for c in s]
    count = 0
    for i in range(1, n):
        if s[i - 1] == '>' and s[i] == '<':
            count += 1

    print(count)


