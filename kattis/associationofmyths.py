input()
input()
_, _, _, _, l = map(int, input().split())

ans = l * l / (3.141592653 * 2.718281828) + 1.0 / (l + 1)
print('{:.9f}'.format(ans))
