pos = [(0, 2), (2, 0), (2, 4), (3, 2), (5, 0), (5, 4), (6, 2)]
find = { int('1110111', 2): '0', 
         int('0100100', 2): '1',
         int('1011101', 2): '2',
         int('1101101', 2): '3',
         int('0101110', 2): '4',
         int('1101011', 2): '5',
         int('1111011', 2): '6',
         int('0100101', 2): '7',
         int('1111111', 2): '8',
         int('1101111', 2): '9' }

def get_digit(strs, start):
    if strs[2][start + 2] == 'x':
        return '+'

    p = 1
    mask = 0
    for x in pos:
        if strs[x[0]][start + x[1]] == 'x':
            mask |= p

        p <<= 1

    return find[mask]

def draw_horiz(grid, row, idx):
    for i in range(5):
        grid[row][i + idx] = 'x'

def draw_vert_top(grid, col):
    for i in range(4):
        grid[i][col] = 'x'

def draw_vert_bot(grid, col):
    for i in range(3, 7):
        grid[i][col] = 'x'

def add_digit(grid, idx, c):
    if c not in '14':
        draw_horiz(grid, 0, idx)

    if c not in '017':
        draw_horiz(grid, 3, idx)

    if c not in '147':
        draw_horiz(grid, 6, idx)

    if c in '045689':
        draw_vert_top(grid, idx)

    if c not in '56':
        draw_vert_top(grid, idx + 4)

    if c in '0268':
        draw_vert_bot(grid, idx)

    if c in '013456789':
        draw_vert_bot(grid, idx + 4)

def handle(ans):
    s = str(ans)
    grid = [['.' for _ in range(len(s) * 6 - 1)] for _ in range(7)]

    idx = 0
    for c in s:
        add_digit(grid, idx, c)
        idx += 6

    for row in grid:
        print(''.join(row))

def main():
    strs = []
    for _ in range(7):
        strs.append(input())

    cols = len(strs[0])
    first = []
    second = []
    in_first = True

    for x in range(0, cols, 6):
        d = get_digit(strs, x)
        if d == '+':
            in_first = False
        else:
            if in_first:
                first.append(d)
            else:
                second.append(d)

    a = int(''.join(first))
    b = int(''.join(second))

    ans = a + b
    handle(ans)

main()
