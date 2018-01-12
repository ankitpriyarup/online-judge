def main():
    n = int(input())
    a = list(map(int, input().split()))
    is_prime = [True] * (max(a) + 1)
    is_prime[0] = is_prime[1] = False
    for x in range(4, len(is_prime), 2):
        is_prime[x] = False

    for i in range(3, len(is_prime), 2):
        if is_prime[i]:
            for j in range(2 * i, len(is_prime), i):
                is_prime[j] = False
    print(sum(is_prime[x] for x in a))

main()
