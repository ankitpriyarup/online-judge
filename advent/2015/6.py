import sys

grid1 = [[0 for _ in xrange(1000)] for _ in xrange(1000)]
grid2 = [[0 for _ in xrange(1000)] for _ in xrange(1000)]

def act(grid, start, end, fn):
    for row in xrange(start[0], end[0] + 1):
        for col in xrange(start[1], end[1] + 1):
            grid[row][col] = fn(grid[row][col])

def main():
    fin = open('6.in', 'r')
    for line in fin.readlines():
        command = line.strip().split()
        start = map(int, command[-3].split(','))
        end = map(int, command[-1].split(','))
        action = command[0]

        if action == "toggle":
            act(grid1, start, end, lambda x: 1 - x)
            act(grid2, start, end, lambda x: x + 2)
        else:
            action = command[1]
            if action == "on":
                act(grid1, start, end, lambda x: 1)
                act(grid2, start, end, lambda x: x + 1)
            else:
                act(grid1, start, end, lambda x: 0)
                act(grid2, start, end, lambda x: max(0, x - 1))
    fin.close()

    print "Part 1", sum([sum(x) for x in grid1])
    print "Part 2", sum([sum(x) for x in grid2])

if __name__ == '__main__':
    main()
