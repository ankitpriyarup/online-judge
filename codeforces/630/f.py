def fact(n):
    if n <= 1:
        return 1
    return n * fact(n - 1)

def choose(n, k):
    return fact(n) / (fact(k) * fact(n - k))

n = int(raw_input())
print choose(n, 7) + choose(n, 6) + choose(n, 5)

