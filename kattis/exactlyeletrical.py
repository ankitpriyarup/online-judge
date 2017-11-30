a, b = map(int, input().split())
c, d = map(int, input().split())

dist = abs(a - c) + abs(b - d)
s = int(input())
print('Y' if dist <= s and (dist % 2) == (s % 2) else 'N')
