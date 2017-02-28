import hashlib
from collections import deque


def md5(s):
    m = hashlib.md5()
    m.update(s.encode('utf-8'))

    return m.hexdigest()


def move(cur, direction):
    x = {'U': -1, 'D': 1, 'L': 0, 'R': 0}
    y = {'U': 0, 'D': 0, 'L': -1, 'R': 1}

    return (cur[0] + x[direction], cur[1] + y[direction])


def valid(pos):
    return all(0 <= c < 4 for c in pos)


def main():
    inp = 'vwbaicqe'
    # inp = 'ihgpwlah'
    pos = (0, 0)
    visited = set([(pos, '')])
    q = deque([(pos, '')])

    while q:
        cur, path = q.popleft()
        if cur == (3, 3):
            print(len(path))
        else:
            md = md5(inp + path)
            for i, direction in enumerate('UDLR'):
                if md[i] in 'bcdef':
                    next_pos = move(cur, direction)
                    new_path = path + direction
                    if valid(next_pos) and (next_pos, new_path) not in visited:
                        visited.add((next_pos, new_path))
                        q.append((next_pos, new_path))





main()
