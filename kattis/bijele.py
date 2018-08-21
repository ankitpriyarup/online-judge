goal = [1, 1, 2, 2, 2, 8]
a = list(map(int, input().split()))
print(' '.join(str(x - y) for x, y in zip(goal, a)))
