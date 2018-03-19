n, a, b = map(int, input().split())
val = (a + b) % (2 * n)
if val < n:
    print('paul')
else:
    print('opponent')
