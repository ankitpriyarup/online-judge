import sys

def main():
    cur = 0
    ans = 0
    for line in sys.stdin:
        line = line.strip()
        if line[0] == '+':
            cur += 1
        elif line[0] == '-':
            cur -= 1
        else:
            l = len(line[line.index(':') + 1:])
            ans += cur * l

    print(ans)


main()
