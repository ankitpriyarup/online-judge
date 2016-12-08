from collections import Counter

def rotate(s, n):
    return ''.join(chr((ord(c) - ord('a') + n) % 26 + ord('a')) for c in s)

def main():
    fin = open('4.in', 'r')
    score = 0
    valid = []
    for line in fin:
        line = line.strip()
        last = line.index('[')
        code_start = line.rfind('-', 0, last) + 1

        slug = line[:code_start - 1]
        code = int(line[code_start:last])
        checksum = line[last + 1:-1]

        slug = slug.replace('-', '')
        freq = Counter(slug)
        best = freq.most_common()
        best.sort(key=lambda x: x[0])
        best.sort(key=lambda x: x[1], reverse=True)

        best = ''.join(x[0] for x in best[:5])
        if checksum == best:
            valid.append((slug, code))
        else:
            print(checksum, best)

    for slug, rot in valid:
        print(rotate(slug, rot), rot)

main()
