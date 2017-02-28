def main():
    fin = open('22.in', 'r')
    nodes = []
    for line in fin:
        name, size, used, avail, _ = line.strip().split()

        x_ind = name.index('x')
        y_ind = name.index('y')

        x = int(name[x_ind + 1:y_ind - 1])
        y = int(name[y_ind + 1:])

        size, used, avail = (int(x[:-1]) for x in (size, used, avail))

        nodes.append((x, y, size, used, avail))

    count = 0

    for i in range(len(nodes)):
        for j in range(len(nodes)):
            if i == j:
                continue
            a = nodes[i]
            b = nodes[j]
            if a[3] != 0 and a[3] <= b[-1]:
                count += 1

    print(count)




main()
