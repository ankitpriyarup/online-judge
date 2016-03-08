def run_length_encoding(s):
    last = ''
    out = []
    for c in s:
        if c != last:
            out.append((c, 1))
            last = c
        else:
            out[-1] = (out[-1][0], out[-1][1] + 1)

    compressed = ""
    for char, freq in out:
        compressed += str(freq) + char

    return compressed

def main():
    base = "1113122113"
    for _ in xrange(40):
        base = run_length_encoding(base)

    print "Part 1", len(base)

    for _ in xrange(10):
        base = run_length_encoding(base)

    print "Part 2", len(base)

if __name__ == '__main__':
    main()
