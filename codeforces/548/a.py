def isPal(cand):
    l = len(cand) 
    for i in range(l):
        if cand[i] != cand[-i - 1]:
            return False

    return True

s = raw_input()
k = int(raw_input())
n = len(s)

works = True
if n % k != 0:
    works = False

l = n / k
for i in range(k):
    frag = s[i*l:(i+1)*l]
    if (not works) or (not isPal(frag)):
        works = False
        break

print 'YES' if works else 'NO'
