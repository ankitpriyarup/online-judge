def r(x, y):
    n = len(x)
    for i in range(n):
        z = y[i:] + y[:i]
        if x == z:
            return i

    return float('inf')

def rot(target, l):
    return sum(r(target, x) for x in l)

def main():
    n = int(input())
    s = [input() for _ in range(n)]

    ans = float('inf')
    for x in s:
        moves = rot(x, s)
        ans = min(ans, moves)

    if ans == float('inf'):
        print(-1)
    else:
        print(ans)

main()
