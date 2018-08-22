n = int(input())
for _ in range(n):
    s = input()
    t = input()
    o = ''.join('.' if x == y else '*' for x, y in zip(s, t))
    print(s)
    print(t)
    print(o)
    print()
