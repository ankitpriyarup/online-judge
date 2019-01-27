T = int(input())
for _ in range(T):
    a, b, n = map(int, input().split())
    poss = n in set(a * i + b * j for i in range(100) for j in range(100))
    print('YES' if poss else 'NO')
