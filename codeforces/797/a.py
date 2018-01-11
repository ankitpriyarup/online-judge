def main():
    n, k = map(int, input().split())
    a = []

    for j in range(k - 1):
        if n == 1:
            break
        for i in range(2, n):
            if i * i > n:
                break
            if n % i == 0:
                a.append(i)
                n //= i
                break

    if n > 1:
        a.append(n)

    if len(a) < k:
        print(-1)
    else:
        print(' '.join(str(x) for x in a))

main()
