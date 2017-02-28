def main():
    n = int(input())
    a = []

    for _ in range(n):
        a.append(int(input()))

    freq = [0] * 6
    swaps = 0

    for i in range(1, 6):
        for j in range(n):
            if a[j] == i:
                if sum(freq[:i + 1]) != j:
                    swaps += 1

                freq[i] += 1


main()
