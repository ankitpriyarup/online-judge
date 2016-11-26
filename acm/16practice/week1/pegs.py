def valid(peg, blocks):
    return 0 <= peg[0] < 5 and 0 <= peg[1] < 5 and peg not in blocks

dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]


def neighbors(peg, blocks):
    for d in range(4):
        neighbor = (peg[0] + dx[d], peg[1] + dy[d])
        landing = (neighbor[0] + dx[d], neighbor[1] + dy[d])
        if valid(neighbor, blocks) and valid(landing, blocks):
            yield neighbor, landing


def solve(grid):
    blocks = {(x, y) for x in range(5) for y in range(5) if grid[x][y] == '#'}
    pegs = frozenset({(x, y) for x in range(5) for y in range(5) if grid[x][y] == 'o'})

    q = [pegs]
    ans = len(pegs)
    visited = set()

    while q:
        cur = q.pop()
        if cur in visited:
            continue

        visited.add(cur)
        ans = min(ans, len(cur))

        for peg in cur:
            for neighbor, landing in neighbors(peg, blocks):
                if neighbor in cur and landing not in cur:
                    q.append((cur - {neighbor, peg}) | {landing})

    return ans


def main():
    t = int(input())
    for _ in range(t):
        grid = []
        for _ in range(5):
            grid.append(input())
        print("The best case ends with {} pegs.".format(solve(grid)))

main()
