from math import sqrt

def gen_primes(cap):
    prime_list = [2]
    not_prime = set()
    for i in xrange(3, cap + 1, 2):
        if i in not_prime:
            continue
        prime_list.append(i)
        for j in xrange(i * i, cap + 1, i):
            not_prime.add(j)

    return prime_list

def factorize(n):
    cap = int(sqrt(n)) + 2
    primes = gen_primes(cap)
    ans = []
    for p in primes:
        while n % p == 0:
            ans.append(p)
            n /= p

    if n != 1:
        ans.append(n)

    return ans

def sum_digits(n):
    return sum(map(int, str(n)))

def is_smith(n):
    digit_sum = sum_digits(n)
    factors = factorize(n)
    #print n, factors
    factor_sum = sum(map(sum_digits, factors))
    return digit_sum == factor_sum

print 1 if is_smith(int(raw_input())) else 0
