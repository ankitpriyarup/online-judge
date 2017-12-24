def main():
    a, b, c = map(int, input().split())
    fs = [lambda x, y: x + y, lambda x, y: x - y, lambda x, y : x * y, lambda x, y: x // y if x % y == 0 else -1]
    for k in range(2):
        for f in fs:
            if f(a, b) == c:
                return 'Possible'

        a, b = b, a

    return 'Impossible'

T = int(input())
for _ in range(T):
    print(main())
