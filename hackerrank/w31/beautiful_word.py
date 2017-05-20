def isvowel(c):
    return c in 'aeiouy'

w = input().strip()
safe = True
for a, b in zip(w, w[1:]):
    if a == b or (isvowel(a) and isvowel(b)):
        safe = False

print('Yes' if safe else 'No')
