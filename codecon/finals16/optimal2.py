# pull from a or c
# cc = number of cons. consonants
def dfs(a, b, c, d, score, length, cc):
    if length == 8 or (a == [] and c == []):
        return score

    ans = score
    if len(a) > 0 and cc < 2:
        ans = max(ans, dfs(b, a[:-1], d, c, score + a[-1], length + 1, cc + 1))
    if len(c) > 0:
        ans = max(ans, dfs(b, a, d, c[:-1], score + c[-1], length + 1, 0))

    return ans

inp = raw_input().split()

odd = []
odd_vow = []
even = []
even_vow = []

for i in xrange(0, len(inp), 2):
    char = inp[i]
    val = int(inp[i + 1])
    if val % 2 == 0:
        if char in "AEIOU":
            even_vow.append(val)
        else:
            even.append(val)
    else:
        if char in "AEIOU":
            odd_vow.append(val)
        else:
            odd.append(val)

odd.sort()
even.sort()

odd_vow.sort()
even_vow.sort()

print dfs(odd, even, odd_vow, even_vow, 0, 0, 0)
