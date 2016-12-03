def main():
    fin = open('3.in', 'r')
    count = 0
    lines = []
    for line in fin:
        a = list(map(int, line.strip().split()))
        lines.append(a)

    for row in range(0, len(lines), 3):
        for col in range(3):
            tri = [lines[row][col], lines[row + 1][col], lines[row + 2][col]]
            tri.sort()
            if tri[0] + tri[1] > tri[2]:
                count += 1

    print(count)

main()
