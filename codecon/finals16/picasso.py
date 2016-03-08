import sys

dirp = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def fill(grid, x, y, old, new):
    q = []
    q.append((x, y))
    while len(q) > 0:
        a, b = q.pop()
        grid[a][b] = new
        for d in dirp:
            na = a + d[0]
            nb = b + d[1]
            if na >= 0 and nb >= 0 and na < len(grid) and nb < len(grid[na]) and grid[na][nb] == old:
                q.append((na, nb))

def main():
    N, M, K = map(int, raw_input().split(','))
    stack = []
    line = raw_input()
    while len(line) > 0:
        command = line[:-1]
        if command == 'redo':
            if len(stack) > 0 and stack[-1] == 'undo':
                stack.pop()
        else:
            stack.append(command)

        try:
            line = raw_input()
        except:
            break

    new_stack = []
    for command in stack:
        if command == 'undo':
            if len(new_stack) > 0:
                new_stack.pop()
        else:
            new_stack.append(command)

    grid = []
    for _ in xrange(N):
        grid.append([])
        for _ in xrange(M):
            grid[-1].append(0)

    for command in new_stack:
        command = command.split()
        if command[0] == 'dot':
            x, y, c = map(int, command[1:])
            grid[x][y] = c
        elif command[0] == 'square':
            x1, y1, x2, y2, c = map(int, command[1:])
            x1, x2 = min(x1, x2), max(x1, x2)
            y1, y2 = min(y1, y2), max(y1, y2)
            for a in xrange(x1, x2 + 1):
                grid[a][y1] = c
                grid[a][y2] = c
            for a in xrange(y1, y2 + 1):
                grid[x1][a] = c
                grid[x2][a] = c
        elif command[0] == 'fill':
            x, y, c = map(int, command[1:])
            fill(grid, x, y, grid[x][y], c)

    for row in grid:
        print ' '.join(map(str, row))

if __name__ == '__main__':
    main()
