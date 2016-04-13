def solve(n):
    if n <= 25:
        return 'a' + chr(ord('a') + n)
    else:
        l = (n // 25) + 2
        if n % 25 == 0:
            l -= 1

        out = ['a']
        for _ in range(1, l):
            if out[-1] == 'a':
                out.append('z')
            else:
                out.append('a')

        score = (l - 1) * 25
        if (score - n) % 2 == 1:
            out[-1] = 'b' if l % 2 == 1 else 'y'
            score -= 1

        d = (score - n) // 2

        out[1] = chr(ord('z') - d)

        return ''.join(out)

def score(s):
    ans = 0
    for i in range(1, len(s)):
        ans += abs(ord(s[i]) - ord(s[i - 1]))

    return ans

def main():
    n = int(input())
    print(solve(n))
    """
    for n in range(1, 1000000):
        print(n)
        if score(solve(n)) != n:
            print(n, "BAD!")
    """

main()
