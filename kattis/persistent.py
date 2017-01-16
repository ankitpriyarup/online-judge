def solve(n):
    if n < 10:
        return 10 + n

    primes = [2, 3, 5, 7]
    counts = [0, 0, 0, 0]

    for i, p in enumerate(primes):
        while n % p == 0:
            counts[i] += 1
            n //= p

    if n > 1:
        return 'There is no such number.'

    freq = [0] * 10
    freq[9] = counts[1] // 2
    counts[1] %= 2
    freq[8] = counts[0] // 3
    counts[0] %= 3
    freq[7] = counts[3]

    if counts[0] > 0 and counts[1] > 0:
        freq[6] = 1
        counts[0] -= 1
        counts[1] -= 1

    freq[5] = counts[2]
    freq[4] = counts[0] // 2
    counts[0] %= 2
    freq[3] = counts[1]
    freq[2] = counts[0]

    out = ''
    chars = ['', '', '2', '3', '4', '5', '6', '7', '8', '9']
    for c, num in zip(chars, freq):
        out += c * num

    return out

def main():
    while True:
        n = int(input())
        if n == -1:
            break

        print(solve(n))

main()
