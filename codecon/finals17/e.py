import sys

sys.setrecursionlimit(int(1e8))

venues = {}
sports = []

def solve(x):
    if x == len(sports):
        return 1

    ans = 0
    for place in sports[x][1]:
        if venues[place] >= sports[x][0]:
            venues[place] -= sports[x][0]
            ans += solve(x + 1)
            venues[place] += sports[x][0]

    return ans


def main():
    n = int(input())

    for _ in range(n):
        name, dur = input().split()
        dur = int(dur)
        venues[name] = dur

    m = int(input())
    for _ in range(m):
        inp = input().split()
        name = inp[1]
        dur = int(inp[2])
        places = inp[3:]

        sports.append((dur, places))

    sports.sort(key = lambda x: len(x[1]))

    ans = solve(0)
    print(ans)

main()
