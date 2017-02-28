from collections import Counter

def main():
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    s = input()
    n = len(s)
    freq = Counter(s)
    odds = []
    for c in alphabet:
        if freq[c] % 2 == 1:
            odds.append(c)

    start = 0
    end = len(odds) - 1
    while start < end:
        freq[odds[start]] += 1
        freq[odds[end]] -= 1
        start += 1
        end -= 1

    out = []
    for c in alphabet:
        for _ in range(freq[c] // 2):
            out.append(c)

    if n % 2 == 1:
        out.append(odds[start])

    for c in reversed(alphabet):
        for _ in range(freq[c] // 2):
            out.append(c)

    print(''.join(out))

main()
