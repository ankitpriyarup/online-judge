from copy import deepcopy
knight_moves = [(-1, -2), (-1, 2), (1, -2), (1, 2),
                (-2, -1), (-2, 1), (2, -1), (2, 1)]
rook_moves = [(1, 0), (-1, 0), (0, 1), (0, -1)]
bishop_moves = [(1, 1), (-1, 1), (1, -1), (-1, -1)]
queen_moves = rook_moves + bishop_moves


def flip(board):
    rev = {'r': 'R', 'b': 'B', 'q': 'Q', 'n': 'N', 'k': 'K',
           'R': 'r', 'B': 'b', 'Q': 'q', 'N': 'n', 'K': 'k'}

    new_board = []
    for row in board:
        new_row = [(x if x == '.' else rev[x]) for x in row]
        new_board.append(new_row)

    return new_board


def in_bounds(a, b):
    return 0 <= a < 8 and 0 <= b < 8


def _get_moves(board, piece, team, moves):
    for move in moves:
        x = piece[0] + move[0]
        y = piece[1] + move[1]
        while in_bounds(x, y):
            if team and 'a' <= board[x][y] <= 'z':
                break
            elif (not team) and 'A' <= board[x][y] <= 'Z':
                break

            yield (x, y)

            if board[x][y] != '.':
                break

            x += move[0]
            y += move[1]


def get_moves(board, piece):
    """Generator for valid moves for piece"""
    piece_type = board[piece[0]][piece[1]]
    team = 'a' <= piece_type <= 'z'
    piece_type = piece_type.upper()

    if piece_type == 'R':
        yield from _get_moves(board, piece, team, rook_moves)
    elif piece_type == 'B':
        yield from _get_moves(board, piece, team, bishop_moves)
    elif piece_type == 'Q':
        yield from _get_moves(board, piece, team, queen_moves)
    elif piece_type == 'N':
        for x, y in knight_moves:
            nx, ny = piece[0] + x, piece[1] + y
            if in_bounds(nx, ny):
                land = board[nx][ny]
                if (team and 'a' <= land <= 'z') or ((not team) and ('A' <= land <= 'Z')):
                    continue
                yield (nx, ny)
    elif piece_type == 'K':
        for a in range(-1, 2):
            for b in range(-1, 2):
                if a == 0 and b == 0:
                    continue
                nx, ny = piece[0] + a, piece[1] + b
                if in_bounds(nx, ny):
                    land = board[nx][ny]
                    if (team and 'a' <= land <= 'z') or ((not team) and ('A' <= land <= 'Z')):
                        continue
                    yield (nx, ny)


def fill_threats(board, piece, threats):
    for move in get_moves(board, piece):
        threats[move[0]][move[1]].add(piece)


def safe(board):
    friends = []
    enemies = []
    for i in range(8):
        for j in range(8):
            if board[i][j] == 'k':
                king_pos = (i, j)
            elif 'a' <= board[i][j] <= 'z':
                friends.append((i, j))
            elif 'A' <= board[i][j] <= 'Z':
                enemies.append((i, j))

    unsafe = []
    for bad in enemies:
        for move in get_moves(board, bad):
            unsafe.append(move)

    return king_pos in unsafe


def solve(board):
    """Return SAFE, CHECKED, OR CHECKMATED"""
    friends = []
    enemies = []
    for i in range(8):
        for j in range(8):
            if board[i][j] == 'k':
                king_pos = (i, j)
            elif 'a' <= board[i][j] <= 'z':
                friends.append((i, j))
            elif 'A' <= board[i][j] <= 'Z':
                enemies.append((i, j))

    unsafe = []
    for bad in enemies:
        for move in get_moves(board, bad):
            unsafe.append(move)

    if king_pos not in unsafe:
        return "SAFE"
    else:
        for m1, m2 in get_moves(board, king_pos):
            old_board = deepcopy(board)

            board[m1][m2] = 'k'
            board[king_pos[0]][king_pos[1]] = '.'

            board = old_board

        for friend in friends:
            for move in get_moves(board, friend):
                # swap the pieces
                old_board = deepcopy(board)
                board[move[0]][move[1]] = board[friend[0]][friend[1]]
                board[friend[0]][friend[1]] = '.'
                if safe(board):
                    return "CHECKED"

                board = old_board

        return "CHECKMATED"


def main():
    move = input()
    board = [list(input()) for _ in range(8)]
    frag = "WHITE IS" if move == 'w' else "BLACK IS"

    if move == 'B':
        board = flip(board)

    status = solve(board)
    print(frag, status)

d = int(input())
for _ in range(d):
    main()
