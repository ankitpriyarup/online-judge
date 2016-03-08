import sys

def print_grid(grid):
    print '\n'.join(map(lambda x: ''.join(x), grid))

def count_neighbors(plane, i, j):
    count = 0

    for dx in xrange(-1, 2):
        for dy in xrange(-1, 2):
            nx = i + dx
            ny = j + dy
            if (nx == i and ny == j) or nx < 0 or ny < 0 or nx >= len(plane) or ny >= len(plane[nx]):
                continue
            if plane[nx][ny] == '#':
                count += 1

    return count

def set_corners(grid):
    for i in xrange(2):
        grid[i][0][0] = '#'
        grid[i][-1][0] = '#'
        grid[i][0][-1] = '#'
        grid[i][-1][-1] = '#'

def update_grid(grid, dest):
    source = 1 - dest
    for i, row in enumerate(grid[source]):
        for j, cell in enumerate(row):
            neighbors = count_neighbors(grid[source], i, j)
            if neighbors == 3 or (cell == '#' and neighbors == 2):
                grid[dest][i][j] = '#'
            else:
                grid[dest][i][j] = '.'

    set_corners(grid)

def main():
    grid = [[], []]
    for line in sys.stdin:
        grid[0].append(list(line.strip()))
        grid[1].append(list(line.strip()))
    
    set_corners(grid)
    print_grid(grid[0])

    for i in xrange(1, 101):
        update_grid(grid, i % 2)
        print
        print 'Step', i
        #print_grid(grid[i % 2])

    count = 0
    for row in grid[0]:
        for cell in row:
            if cell == '#':
                count += 1

    print count


if __name__ == '__main__':
    main()
