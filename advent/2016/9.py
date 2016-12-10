from collections import Counter
import itertools

def decompress(line):
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

            for _ in range(repeat_count):
                out.append(chunk)

            index = end + 1 + chunk_len
        else:
            out.append(line[index])
            index += 1

    return ''.join(out)

def main():
    fin = open('9.in', 'r')

    score = 0
    for line in fin.readlines():
        inp = line.strip()
        dec = decompress(inp)
        score += len(dec)

    print(score)

main()
