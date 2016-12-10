from collections import Counter
import itertools

def main():
    fin = open('8.in', 'r')
    grid = [[0 for _ in range(50)] for _ in range(6)]

    for line in fin.readlines():
        command = line.strip().split()
        if command[0] == 'rect':
            width, height = map(int, command[1].split('x'))
            for x in range(height):
                for y in range(width):
                    grid[x][y] = 1
        elif command[1] == 'row':
            row = int(command[2].split('=')[1])
            amount = int(command[-1])
            new_row = []
            for i in range(50):
                new_row.append(grid[row][(i - amount + 50) % 50])
            grid[row] = new_row
        else: # column
            col = int(command[2].split('=')[1])
            amount = int(command[-1])
            new_col = []
            for i in range(6):
                new_col.append(grid[(i - amount + 6) % 6][col])

            for i in range(6):
                grid[i][col] = new_col[i]

    fin.close()

    for row in grid:
        print(''.join(map(str, row)))

    ans = sum(sum(row) for row in grid)
    print(ans)

main()
