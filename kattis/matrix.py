import sys

def main():
    lines = []
    for line in sys.stdin:
        lines.append(line.strip())

    case = 1

    for i in range(0, len(lines), 3):
        a, b = map(int, lines[i].split())
        c, d = map(int, lines[i + 1].split())

        print('Case ' + str(case) + ':')
        det = a * d - b * c

        print(d // det, -b // det)
        print(-c // det, a // det)

        case += 1

main()
