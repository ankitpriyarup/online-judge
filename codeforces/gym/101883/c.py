def latin(word):
    caps = False
    if 'A' <= word[0] <= 'Z':
        word = word[0].lower() + word[1:]
        caps = True
    latin = word[1:] + word[0] + 'ay'
    if caps:
        latin = latin[0].upper() + latin[1:]
    return latin

T = int(input())
for _ in range(T):
    line = [word.strip() for word in input().split()]
    out = [latin(word) for word in line]
    print(' '.join(out))
