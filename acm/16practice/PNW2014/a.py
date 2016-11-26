def valid(s):
    return not (s[0] == '0' and len(s) > 1) and (not s.startswith('-0'))

def main():
    T = int(input())
    for _ in range(T):
        s = input()
        eq = s.index('=')
        c = s[(eq + 1):]
        if '+' in s:
            d = s.index('+')
            op = lambda a, b: a + b
        elif '*' in s:
            d = s.index('*')
            op = lambda a, b: a * b
        else:
            d = s.index('-', 1)
            op = lambda a, b: a - b

        a = s[:d]
        b = s[d + 1:eq]

        ans = -1
        for rep in range(0, 10):
            strrep = str(rep)
            if strrep in s:
                continue
            ap = a.replace('?', strrep)
            bp = b.replace('?', strrep)
            cp = c.replace('?', strrep)

            if valid(ap) and valid(bp) and valid(cp) and op(int(ap), int(bp)) == int(cp):
                ans = rep
                break

        print(ans)

main()
