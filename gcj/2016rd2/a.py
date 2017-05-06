def solve():
    n, r, p, s = map(int, input().split())
    """
    Let x be the number of rock-paper games.
    Then the remaining rocks and papers must play scissors.

    Then r - x + p - x == s
    So x = (r + p - s) / 2

    Check if that's possible, then recurse
    """

    old_n = n

    while n > 0:
        x = (r + p - s) // 2
        if x < 0 or x > r or x > p:
            return 'IMPOSSIBLE'
        y = r - x
        if y < 0 or y > r or y > s:
            return 'IMPOSSIBLE'
        z = p - x
        if z < 0 or z > p or z > s:
            return 'IMPOSSIBLE'

        r, p, s = r - x, x, p - x
        n -= 1

    # Now we know it's possible, so build the string

    if r == 1:
        ans = 'R'
    elif p == 1:
        ans = 'P'
    elif s == 1:
        ans = 'S'

    m = {'R': 'RS', 'P': 'PR', 'S': 'PS'}
    while n < old_n:
        ans = ''.join(''.join(m[x] for x in c) for c in ans)
        n += 1

    ans = list(ans)
    while len(ans) > 1:
        chunks = []
        for i in range(0, len(ans), 2):
            a = ans[i]
            b = ans[i + 1]
            if a < b:
                chunks.append(a + b)
            else:
                chunks.append(b + a)

        ans = chunks

    return ''.join(ans)

def main():
    t = int(input())
    for tt in range(t):
        print('Case #{}: {}'.format(tt + 1, solve()))

main()
