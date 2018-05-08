t = int(input())
for _ in range(t):
    n = int(input())
    print('{} is {}'.format(n, 'even' if n % 2 == 0 else 'odd'))
