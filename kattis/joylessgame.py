memo = {}
def wins(s):
    assert(len(s) >= 2)
    assert(all(a != b for a, b in zip(s, s[1:])))

    if s in memo:
        return memo[s]

    n = len(s)
    c = set()
    for i in range(1, n - 1):
        if s[i - 1] != s[i + 1]:
            t = s[:i] + s[i + 1:]
            c.add(wins(t))

    g = 0
    while g in c:
        g += 1
    print(s, g)
    memo[s] = g
    return g

def solve(s):
    x = len(s)
    x += (s[0] == s[-1])
    return (x & 1) == 1

T = int(input())
for _ in range(T):
    s = input()
    n = len(s)
    guess = solve(s)
    print('Chikapu' if guess else 'Bash')
