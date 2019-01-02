import sys

n, m = map(int, sys.stdin.readline().split())
w = list(map(int, sys.stdin.readline().split()))
w.sort(reverse=True)
fishermen = []
for _ in range(m):
    x, p = map(int, sys.stdin.readline().split())
    fishermen.append((p, x))
fishermen.sort(reverse=True)

ptr = 0
ans = 0
sold = 0
for x in w:
    if sold == fishermen[ptr][1]:
        sold = 0
        ptr += 1

    if ptr >= m:
        break

    sold += 1
    ans += fishermen[ptr][0] * x

print(ans)
