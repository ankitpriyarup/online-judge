from collections import Counter

def valid(line):
    in_bad = '[' in line[:2] and ']' not in line[:2]
    possible = False
    for i in range(3, len(line)):
        if '[' not in line[i - 3:i + 1] and ']' not in line[i - 3:i + 1]:
            if line[i - 3] == line[i] and line[i - 2] == line[i - 1] and line[i] != line[i - 1]:
                if in_bad:
                    return False
                else:
                    possible = True

        if line[i] == ']':
            in_bad = False
        elif line[i] == '[':
            in_bad = True

    return possible

def main():
    fin = open('7.in', 'r')
    count = 0
    for line in fin.readlines():
        if valid(line.strip()):
            count += 1

    print(count)
    fin.close()

main()
