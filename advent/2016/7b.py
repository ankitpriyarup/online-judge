from collections import Counter

def valid(line):
    in_bad = '[' in line[:2] and ']' not in line[:2]
    outside = set()
    inside = set()
    for i in range(2, len(line)):
        if '[' not in line[i - 2:i + 1] and ']' not in line[i - 2:i + 1]:
            if line[i - 2] == line[i] and line[i] != line[i - 1]:
                if in_bad:
                    inside.add(line[i-2:i+1])
                else:
                    outside.add(line[i-2:i+1])

        if line[i] == ']':
            in_bad = False
        elif line[i] == '[':
            in_bad = True

    print(line, inside, outside)
    for chunk in outside:
        x = chunk[0]
        y = chunk[1]
        target = y + x + y
        print(chunk, target)
        if target in inside:
            return True

    return False

def main():
    fin = open('7.in', 'r')
    count = 0
    for line in fin.readlines():
        if valid(line.strip()):
            count += 1

    print(count)
    fin.close()

main()
