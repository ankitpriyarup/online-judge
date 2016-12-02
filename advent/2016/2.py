grid = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
dirs = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}

def fix(x):
    return min(2, max(0, x))

def combine(a, b):
    return (fix(a[0] + b[0]), fix(a[1] + b[1]))

def main():
    n = int(input())
    pos = (1, 1)
    for _ in range(n):
        line = input()
        for c in line:
            d = dirs[c]
            pos = combine(pos, d)

        print(grid[pos[0]][pos[1]])

main()
