p, q, s = map(int, input().split())
works = any(x % p == 0 and x % q == 0 for x in range(1, s + 1))
print('yes' if works else 'no')
