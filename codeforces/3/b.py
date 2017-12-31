def solve(by_w, b, v):
    rem = min(v - 2 * b, len(by_w[1]))
    if rem < 0:
        return (-1, 0, 0)

    score = 0 if b == 0 else by_w[2][b - 1][0]
    if rem > 0:
        score += by_w[1][rem - 1][0]

    return (score, rem, b)

def main():
    n, v = map(int, input().split())
    by_w = [[] for _ in range(3)]

    for i in range(n):
        t, p = map(int, input().split())
        by_w[t].append((p, i + 1))

    a, b = len(by_w[1]), len(by_w[2])
    by_w[1].sort(reverse=True)
    by_w[2].sort(reverse=True)

    for i in range(1, a):
        by_w[1][i] = (by_w[1][i][0] + by_w[1][i - 1][0], by_w[1][i][1])

    for i in range(1, b):
        by_w[2][i] = (by_w[2][i][0] + by_w[2][i - 1][0], by_w[2][i][1])

    score = (-1, 0, 0)
    for i in range(b + 1):
        t = solve(by_w, i, v)
        score = max(score, t)

    inds = [by_w[1][i][1] for i in range(score[1])]
    inds += [by_w[2][i][1] for i in range(score[2])]
    inds.sort()

    print(score[0])
    print(' '.join(str(x) for x in inds))

main()
