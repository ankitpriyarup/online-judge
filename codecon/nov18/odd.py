n = int(input())
a = list(map(int, input().split()))
evens = sum(x % 2 == 0 for x in a)
if evens <= 1:
    print('NO')
else:
    print('YES')
