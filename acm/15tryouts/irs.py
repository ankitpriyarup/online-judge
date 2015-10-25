def rep_max(s):
    if s[0] == '-':
        return -1 * rep_min(s[1:])
    return int(''.join(['9' if c == '#' else c for c in s]))
def rep_min(s):
    if s[0] == '-':
        return -1 * rep_max(s[1:])
    s2 = ''.join(['0' if c == '#' else c for c in s])
    if s2[0] == '0':
        s2 = '1' + s2[1:]
    return int(s2)

def main():
    T = int(raw_input())
    for case in xrange(1, T + 1):
        N = int(raw_input())
        vals = []
        for _ in xrange(N):
            vals.append(raw_input())
        minn = sum(map(rep_min, vals))
        maxx = sum(map(rep_max, vals))
        print "Case %d: %d %d" % (case, minn, maxx)

main()
