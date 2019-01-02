from collections import *
import itertools
import random
import sys

sys.setrecursionlimit(1000000)

class Unit(object):
    def __init__(self, r, c, is_elf, atk):
        self.r = r
        self.c = c
        self.is_elf = is_elf
        self.atk = 3 if not is_elf else atk
        self.hp = 200

    def is_dead(self):
        return self.hp <= 0

    def __repr__(self):
        return '{} at {} {}. HP: {} / 200'.format('E' if self.is_elf else 'G', self.r, self.c, self.hp)

moves = [(-1, 0), (0, -1), (0, 1), (1, 0)]

def in_range(r, c, n, m):
    return 0 <= r and r < n and 0 <= c and c < m

def occupied(units, r, c):
    return any((r, c) == (u.r, u.c) for u in units if not u.is_dead())

def bfs(grid, src_r, src_c, units):
    n = len(grid)
    m = len(grid[0])
    dist = [[float('inf') for _ in range(m)] for _ in range(n)]
    dist[src_r][src_c] = 0
    dq = deque([(src_r, src_c)])
    while dq:
        x, y = dq.popleft()
        for dx, dy in moves:
            nx, ny = x + dx, y + dy
            if in_range(nx, ny, n, m) \
                and grid[nx][ny] != '#' \
                and not occupied(units, nx, ny) \
                and dist[x][y] + 1 < dist[nx][ny]:
                dist[nx][ny] = dist[x][y] + 1
                dq.append((nx, ny))

    return dist

def find_goal(target_inds, dist, units):
    n = len(dist)
    m = len(dist[0])

    target_pos = set()
    min_dist = float('inf')
    for idx in target_inds:
        r, c = units[idx].r, units[idx].c
        for dx, dy in moves:
            nx, ny = r + dx, c + dy
            if in_range(nx, ny, n, m):
                if dist[nx][ny] < min_dist:
                    target_pos = set()
                    min_dist = dist[nx][ny]
                if dist[nx][ny] == min_dist:
                    target_pos.add((nx, ny))

    target_pos = list(target_pos)
    target_pos.sort()
    return target_pos[0] if target_pos else (-1, -1)

def sim(grid, elf_atk):
    n = len(grid)
    m = len(grid[0])
    units = []
    for i in range(n):
        for j in range(m):
            if grid[i][j] in 'EG':
                unit = Unit(i, j, grid[i][j] == 'E', elf_atk)
                units.append(unit)
                grid[i][j] = '.'

    round_num = 0
    done = False
    while True:
        if done:
            break

        inds = list(range(len(units)))
        inds.sort(key=lambda i: (units[i].r, units[i].c))
        for ind in inds:
            if units[ind].is_dead():
                continue

            # move
            target_inds = [x for x in inds if units[ind].is_elf != units[x].is_elf and not units[x].is_dead()]

            if not target_inds:
                done = True
                break

            src_dist = bfs(grid, units[ind].r, units[ind].c, units)

            goal = find_goal(target_inds, src_dist, units)
            if goal[0] < 0:
                continue

            goal_dist = src_dist[goal[0]][goal[1]]
            if goal_dist == float('inf'):
                continue

            sink_dist = bfs(grid, goal[0], goal[1], units)
            cands = [(units[ind].r + dx, units[ind].c + dy) for dx, dy in moves]
            cands.append((units[ind].r, units[ind].c))
            min_dist = min(sink_dist[r][c] for r, c in cands if in_range(r, c, n, m))
            for r, c in cands:
                if sink_dist[r][c] == min_dist:
                    units[ind].r = r
                    units[ind].c = c
                    break

            # attack
            neighbors = [(units[ind].r + dx, units[ind].c + dy) for dx, dy in moves]
            neighbors = [(r, c) for r, c in neighbors if in_range(r, c, n, m)]
            options = [x for x in target_inds for r, c in neighbors if (r, c) == (units[x].r, units[x].c)]
            hashes = [(units[x].hp, units[x].r, units[x].c, x) for x in options]
            hashes.sort()
            if hashes:
                hit = hashes[0][3]
                units[hit].hp -= units[ind].atk
        else:
            round_num += 1

    elf_win = all(not unit.is_dead() for unit in units if unit.is_elf)
    elf_hp = sum(unit.hp for unit in units if unit.is_elf)
    outcome = round_num * elf_hp

    return elf_win, outcome

def main():
    grid = [list(line.strip()) for line in sys.stdin]
    lo = 3
    hi = int(1e9)
    while lo + 1 < hi:
        mid = (lo + hi) // 2
        copy_grid = [list(row) for row in grid]
        win, ans = sim(copy_grid, mid)
        if win:
            out_ans = ans
            hi = mid
        else:
            lo = mid

    print(out_ans)

main()
