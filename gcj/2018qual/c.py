import random

random.seed(0xcafebabe)

def gen_cell(x, y):
    dx = random.randint(-1, 1)
    dy = random.randint(-1, 1)

    return (x + dx, y + dy)

def build_options(grid):
    h, w = len(grid), len(grid[0])
    res = []
    for i in range(1, h - 1):
        for j in range(1, w - 1):
            score = 9 - sum(grid[i + dx][j + dy] for dx in range(-1, 2) for dy in range(-1, 2))
            for _ in range(score):
                res.append((i, j))
    return res

def works(w, h):
    grid = [[False for _ in range(w)] for _ in range(h)]
    s = 0
    moves = 0
    while s < w * h:
        ways = build_options(grid)
        x, y = gen_cell(*random.choice(ways))
        if not grid[x][y]:
            s += 1
        grid[x][y] = True
        moves += 1
    return moves

def main():
    size = 200
    iters = 100
    for w in range(3, 15):
        h = (size + w - 1) // w
        num = max(works(w, h) for _ in range(iters))
        print(w, h, num)

main()
