import heapq
from math import sqrt

def sieve(CAP = 10 ** 6 + 7):
    primes = [2]
    pq = []
    for x in range(3, CAP, 2):
        if pq and pq[0][0] == x:
            while pq and pq[0][0] == x:
                v, m = heapq.heappop(pq)
                heapq.heappush(pq, (v + m + m, m))
        else:
            primes.append(x)
            heapq.heappush(pq, (x * x, x))

    return primes

def is_prime(x, primes):
    for p in primes:
        if x % p == 0:
            return p

    return x

def main():
    input()
    N, count = map(int, input().split())
    primes = sieve()

    print("Case #1:")
    for i in range(2 ** (N - 2), 2 ** (N - 1)):
        s = bin(i)[2:] + '1'
        jamcoin = True
        proofs = []

        for base in range(2, 11):
            x = int(s, base)
            val = is_prime(x, primes)
            if val == x:
                jamcoin = False
                break
            else:
                proofs.append(val)

        if jamcoin:
            count -= 1
            print(s, ' '.join(map(str, proofs)))

        if count == 0:
            break

main()
