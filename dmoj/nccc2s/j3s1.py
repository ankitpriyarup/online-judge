n = int(input())
a = [int(input()) for _ in range(n)]

a.sort()

moves = min(sum(a) - a[-1], sum(a) // 2)

print(moves)
