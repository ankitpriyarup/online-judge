w, s, c, k = map(int, input().split())
# let a = min(s, w + c)
# possible if
# 1) a < k
# 2) a == k and b == k
a = min(s, w + c)
b = max(s, w + c)
poss = a < k
poss = poss or (a <= k and b <= 2 * k)
poss = poss or sum(x == 0 for x in (w, s, c)) >= 2
poss = poss and (k > 0 or w + s + c == 0)
print('YES' if poss else 'NO')
