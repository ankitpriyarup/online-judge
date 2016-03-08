from collections import defaultdict
import sys

repl = {}
sys.setrecursionlimit(100000)

def create(start, end, text):
    if start not in text:
        return set()

    indexes = [text.index(start)]
    while True:
        try:
            indexes.append(text.index(start, indexes[-1] + 1))
        except ValueError:
            break

    l = len(start)
    ret = set()
    for ind in indexes:
        new = text[:ind] + end + text[(ind + l):]
        ret.add(new)

    return ret

def ans1(repl):
    ans = set()
    for key in repl:
        for val in repl[key]:
            ans |= create(key, val, text)

    print len(ans)

def main():
    text = ''
    for line in sys.stdin:
        line = line.strip()
        if line == '':
            continue

        if '=>' in line:
            a, b = [x.strip() for x in line.split(' => ')]
            repl[b] = a
        else:
            text = line

    count = 0
    while text != 'e':
        longest_key = ''
        for k in repl:
            if len(k) > len(longest_key) and k in text:
                longest_key = k

        i = text.index(longest_key)
        text = text[:i] + repl[longest_key] + text[i + len(longest_key):]
        count += 1

    print count

if __name__ == '__main__':
    main()
