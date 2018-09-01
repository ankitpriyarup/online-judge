a, b, c = map(int, input().split())
x, y, z = map(int, input().split())
opts = [a / x, b / y, c / z]
ratio = min(opts)
left = [have - ratio * base for have, base in zip([a, b, c], [x, y, z])]
print(' '.join(str(x) for x in left))
