T = int(input())
for _ in range(T):
    n, s, t = map(int, input().split())
    print(max(n - s, n - t) + 1)
