import sys

T = int(sys.stdin.readline())
for _ in range(T):
    sys.stdin.readline()
    n = int(sys.stdin.readline())
    goals = []
    for _ in range(n):
        a, b = sys.stdin.readline().split()
        goals.append(int(b) - 1)

    goals.sort()
    ans = 0
    for i, x in enumerate(goals):
        ans += abs(i - x)
    print(ans)
