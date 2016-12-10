from collections import Counter
import itertools

def decompress(line, mult=1):
    # chunk, count
    out = []
    in_marker = False
    index = 0
    n = len(line)

    while index < n:
        if line[index] == '(':
            end = line.index(')', index + 1)
            command = line[index + 1:end].split('x')
            chunk_len, repeat_count = map(int, command)
            chunk = line[end + 1: end + 1 + chunk_len]

            out.append((chunk, mult * repeat_count))

            index = end + 1 + chunk_len
        else:
            out.append((line[index], mult))
            index += 1

    return out

def main():
    fin = open('9.in', 'r')

    score = 0
    for line in fin.readlines():
        inp = line.strip()
        dec = decompress(inp)

        while any('(' in x[0] for x in dec):
            new = []
            for chunk, count in dec:
                if '(' in chunk:
                    for thing in decompress(chunk, count):
                        new.append(thing)
                else:
                    new.append((chunk, count))
            dec = new

        print(inp, dec)

        score = sum(len(x[0]) * x[1] for x in dec)

    print(score)

main()
