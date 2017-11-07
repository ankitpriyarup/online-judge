def score(c):
    return ord(c) - ord('A')

def shift(x, amt):
    return chr((score(x) + amt) % 26 + ord('A'))

def rot(x):
    s = sum(score(c) for c in x)

    return ''.join(shift(c, s % 26) for c in x)

def main():
    s = input()
    n = len(s)
    a = s[:n // 2]
    b = s[n // 2:]
    a = rot(a)
    b = rot(b)
    out = [shift(x, score(y)) for x, y in zip(a, b)]
    print(''.join(out))

main()
