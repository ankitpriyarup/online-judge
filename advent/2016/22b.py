def main():
    fin = open('22.in', 'r')
    nodes = {}
    target = (0, 0)
    empty = (0, 0)
    board = [['.' for _ in range(30)] for _ in range(36)]
    for line in fin:
        name, size, used, avail, _ = line.strip().split()

        x_ind = name.index('x')
        y_ind = name.index('y')

        x = int(name[x_ind + 1:y_ind - 1])
        y = int(name[y_ind + 1:])

        size, used, avail = (int(x[:-1]) for x in (size, used, avail))

        if used > 89:
            board[x][y] = '#'

        nodes[(x, y)] = ((size, used, avail))

        if used == 0:
            empty = (x, y)
            board[-2][0] = 'E'

        target = (max(target[0], x), target[1])

    board[-1][0] = 'G'
    for row in board:
        print(''.join(row))

    # It takes 35 moves to get to the second to top row
    moves = empty[0] - 1
    moves += empty[1]
    moves += len(board) - 3
    print(moves)
    empty = [len(board) - 2, 0]
    goal = [len(board) - 1, 0]

    while goal[0] > 0:
        moves += 1
        goal[0] -= 1
        empty[0] += 1
        if goal[0] == 0:
            break

        # move empty to in front of goal
        moves += 4
        empty[0] -= 2

    print(moves)

main()
