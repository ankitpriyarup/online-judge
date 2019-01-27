n, k = map(int, input().split())
primes = [2]
for d in range(3, n + n + 3, 2):
    is_prime = True
    for x in range(3, d):
        if x * x > d:
            break
        if d % x == 0:
            is_prime = False
            break

    if is_prime:
        primes.append(d)

found = []
for x, y in zip(primes, primes[1:]):
    v = 1 + x + y
    if v > n:
        break

    if v in primes:
        found.append(v)

print('YES' if k <= len(found) else 'NO')
