def f(x):
    d = x % 4
    if d == 0:
        return x
    elif d == 1:
        return 1
    elif d == 2:
        return x + 1
    else:
        return 0

T = int(input())
for _ in range(T):
    u, v = map(int, input().split())
    print(f(v) ^ f(u - 1))
