def main(tc):
    r, c = map(int, input().split())
    grid = [list(input()) for _ in range(r)]
    grid = grid[::-1]
    print('Test', tc)
    for row in grid:
        print(''.join(reversed(row)))

T = int(input())
for x in range(T):
    main(x + 1)
