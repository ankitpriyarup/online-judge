i, j, k = range(2, 5)
times_table = [[], [0, 1, i, j, k], [0, i, -1, k, -j], [0, j, -k, -1, i], [0, k, j, -i, -1]]

def prod(q1, q2):
    negative = q1 * q2 < 0
    return (-1 if negative else 1) * times_table[abs(q1)][abs(q2)]

def parse_q(c):
    if c == 'i':
        return i
    elif c == 'j':
        return j
    elif c == 'k':
        return k

def is_neg1(inp, X):
    value = 1
    for q in inp:
        value = prod(value, q)
    single = value
    value = 1
    for ab in xrange(X % 4):
        value = prod(value, single)
    return value == -1

def solve(s, X):
    inp = map(parse_q, s)
    if not is_neg1(inp, X):
        return "NO"

    full = inp * min(X, 12)
    i_val = 1
    j_val = 1
    for q in full:
        if i_val != i:
            i_val = prod(i_val, q)
        elif j_val != j:
            j_val = prod(j_val, q)

    if i_val != i or j_val != j:
        return "NO"

    return "YES"

def main():
    T = int(raw_input())
    for tc in xrange(1, T + 1):
        L, X = map(int, raw_input().split())
        s = raw_input()
        print "Case #%d: %s" % (tc, solve(s, X))

if __name__ == '__main__':
    main()
