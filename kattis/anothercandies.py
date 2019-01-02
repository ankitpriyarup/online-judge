T = int(input())
for _ in range(T):
    input()
    n = int(input())
    x = sum(int(input()) for _ in range(n)) % n
    print('YES' if x == 0 else 'NO')
