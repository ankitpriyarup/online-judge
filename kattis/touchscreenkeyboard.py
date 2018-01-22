from functools import lru_cache
keyboard = ['qwertyuiop', 'asdfghjkl', 'zxcvbnm']

@lru_cache(maxsize=None)
def index(c):
    for i, row in enumerate(keyboard):
        if c in row:
            return (i, row.index(c))

def score(a, b):
    ans = 0
    for x, y in zip(a, b):
        x1, y1 = index(x)
        x2, y2 = index(y)

        ans += abs(x1 - x2) + abs(y1 - y2)

    return ans

def main():
    a, b = input().split()
    b = int(b)

    lines = []
    for _ in range(b):
        lines.append(input())

    lines = [(line, score(a, line)) for line in lines]
    lines.sort(key=lambda x: (x[1], x[0]))

    for a, b in lines:
        print(a, b)

T = int(input())
for _ in range(T):
    main()
