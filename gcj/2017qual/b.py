from collections import Counter

"""
def tidy(x):
    return ''.join(sorted(str(x))) == str(x)

def brute(n):
    t = list(filter(tidy, range(1, n + 1)))

    return t[-1]
"""

def fast(n):
    s = list(str(n))
    c = Counter()

    last_bad = len(s)
    for i in range(len(s) - 1, -1, -1):
        x = int(s[i])
        for y in range(x):
            if c[y]:
                last_bad = i

        if last_bad == i:
            c.clear()

        c[x] += 1

    if last_bad == len(s):
        return n

    while last_bad > 0 and s[last_bad] == s[last_bad - 1]:
        last_bad -= 1

    s[last_bad] = str(int(s[last_bad]) - 1)
    if s[0] == '0':
        return '9' * (len(s) - 1)
    for j in range(last_bad + 1, len(s)):
        s[j] = '9'

    return ''.join(s)

def solve():
    n = int(input())

    return fast(n)

def main():
    t = int(input())
    for tt in range(t):
        print('Case #{}: {}'.format(tt + 1, solve()))

main()
