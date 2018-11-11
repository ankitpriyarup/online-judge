T = int(input())
d = {
        'at': '@',
        'and': '&',
        'one': '1',
        'won': '1',
        'to': '2',
        'too': '2',
        'two': '2',
        'four': '4',
        'for': '4',
        'bea': 'b',
        'be': 'b',
        'bee': 'b',
        'sea': 'c',
        'see': 'c',
        'eye': 'i',
        'oh': 'o',
        'owe': 'o',
        'are': 'r',
        'you': 'u',
        'why': 'y',
}

for _ in range(T):
    s = input()
    t = []
    p = 0
    n = len(s)
    while p < n:
        cand = []
        for key in d:
            l = len(key)
            if s[p:p+l].lower() == key:
                cand.append(key)
        if cand:
            cand.sort()
            key = cand[-1]
            if s[p] in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
                t.append(d[key].upper())
            else:
                t.append(d[key])
            p += len(key)
        else:
            t.append(s[p])
            p += 1

    print(''.join(t))
