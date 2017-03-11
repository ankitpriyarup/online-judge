import itertools

fact = [1]
for i in range(1, 50):
    fact.append(i * fact[-1])

def choose(n, k):
    return fact[n] // (fact[k] * fact[n - k])

def count(n):
    sign = 1
    ans = 0
    for k in range(n + 1):
        ans += sign * choose(n, k) * fact[n - k]
        sign = -sign

    return fact[n] - ans


def main():
    ans = 0.6321205588285577
    n = int(input())
    if n >= 18:
        print(ans)
    else:
        print(count(n) / fact[n])

main()
