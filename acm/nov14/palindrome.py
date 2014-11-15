from collections import Counter

facts = [1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000]

t = int(raw_input())
for lll in xrange(t):
    l = int(raw_input())
    s = raw_input()
    freq = Counter(s)
    
    if l % 2 == 1:
        for x in freq:
            if freq[x] % 2 == 1:
                freq[x] -= 1
                break

    if l % 2 == 1:
        l -= 1

    ans = facts[l / 2]
    for x in freq:
        if freq[x] % 2 == 1:
            ans = 0
            break
        ans /= facts[freq[x] / 2]

    print ans
