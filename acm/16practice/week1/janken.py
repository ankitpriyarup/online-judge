import heapq
from collections import defaultdict, namedtuple

starts = [5, 4, 3, 2, 1, 1, 1, 1, 1]
ends = [9, 9, 9, 9, 9, 8, 7, 6, 5]

Unit = namedtuple("unit", ["unit_type", "team", "moves"])


def parse(pos):
    row = ord(pos[0]) - ord('A')
    col = int(pos[1])

    return (row, col)


def read_board():
    board = []
    for start, end in zip(starts, ends):
        row = ['U' for _ in range(10)]
        data = input().strip().split()
        for cell, x in zip(data, range(start, end + 1)):
            row[x] = cell

        board.append(row)

    return board


def read_units():
    red_team, blue_team = map(int, input().split())
    units = {}
    for _ in range(red_team):
        unit_type, pos = input().split()
        x, y = parse(pos)
        units[(x, y)] = Unit(unit_type, 0, 10)

    for _ in range(blue_team):
        unit_type, pos = input().split()
        x, y = parse(pos)
        units[(x, y)] = Unit(unit_type, 1, 10)

    return units


dx = [-1, -1, 0, 0, 1, 1]
dy = [0, 1, -1, 1, -1, 0]


def valid(board, units, x, y, unit_type, team):
    weakness = {'G': 'M', 'M': 'S', 'S': 'G'}
    if x < 0 or y < 0 or x >= len(board) or y >= len(board[x]) or board[x][y] == 'U':
        return False

    p = (x, y)
    if p in units and units[p].team != team:
        return False

    # check if there's enemies nearby
    for d in range(6):
        nx, ny = x + dx[d], y + dy[d]
        if (nx, ny) in units:
            obstacle = units[(nx, ny)]
            if obstacle.unit_type == weakness[unit_type] and obstacle.team != team:
                return False

    return True


def cost(board, x, y):
    score = {'F': 1, 'W': 2, 'H': 3, 'M': 4}
    return score[board[x][y]]


def dijkstra(board, units, parsed_start, parsed_end, unit):
    INF = 1e9

    heap = [(parsed_start, 0)]
    dist = defaultdict(lambda: INF)
    dist[parsed_start] = 0
    visited = set()

    while heap:
        cur, cur_dist = heapq.heappop(heap)
        if cur in visited:
            continue

        visited.add(cur)
        if dist[cur] < cur_dist:
            continue
        dist[cur] = min(dist[cur], cur_dist)

        for d in range(6):
            nx, ny = cur[0] + dx[d], cur[1] + dy[d]
            if (nx, ny) not in visited and valid(board, units, nx, ny, unit.unit_type, unit.team):
                new_dist = cur_dist + cost(board, nx, ny)
                if new_dist < dist[(nx, ny)]:
                    dist[(nx, ny)] = new_dist
                    heapq.heappush(heap, ((nx, ny), new_dist))

    return -1 if dist[parsed_end] == INF else dist[parsed_end]


def main():
    n = int(input())
    for game_num in range(1, n + 1):
        print("Game #{}".format(game_num))
        board = read_board()
        units = read_units()

        v = int(input())
        for move_num in range(1, v + 1):
            start, end = input().split()
            parsed_start, parsed_end = parse(start), parse(end)
            if (parsed_start not in units) or (parsed_end in units):
                print("Move #{0} ({1} -> {2}): Unsuccessful"
                      .format(move_num, start, end, 5))
                continue

            unit = units.pop(parsed_start)
            distance = dijkstra(board, units, parsed_start, parsed_end, unit)
            if (distance < 0) or (distance > unit.moves):
                print("Move #{0} ({1} -> {2}): Unsuccessful"
                      .format(move_num, start, end, 5))

                units[parsed_start] = unit
            else:
                moves_left = unit.moves - distance
                print("Move #{0} ({1} -> {2}): Successful ({3} points left)"
                      .format(move_num, start, end, moves_left))

                units[parsed_end] = Unit(unit.unit_type, unit.team, moves_left)

main()
