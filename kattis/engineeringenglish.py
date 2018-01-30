import sys

seen = set()
for line in sys.stdin:
    words = line.strip().split()
    out = []
    for word in words:
        l = word.lower()
        if l in seen:
            out.append('.')
        else:
            out.append(word)

        seen.add(l)

    print(' '.join(out))
