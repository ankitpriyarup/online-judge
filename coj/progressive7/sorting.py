def main():
    values = raw_input()
    try:
        year = 0
        while values:
            year += 1
            if values == "0":
                return
            n, alphabet = values.split()
            n = int(n)
            words = []
            for i in xrange(n):
                words.append(raw_input())
                words = sorted(words, key=lambda word: [alphabet.index(c) for c in word])
            print 'year %d' % year
            print '\n'.join(words)
            values = raw_input()
    except EOFError:
        return

main()
