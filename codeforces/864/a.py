from collections import Counter
def main():
    n = int(input())
    a = []
    for _ in range(n):
        a.append(int( input()))

    c = Counter(a)
    freqs = c.most_common()
    safe = len(freqs) == 2 and freqs[0][1] == freqs[1][1] and freqs[0][1] + freqs[1][1] == n
    if safe:
        print('YES')
        print(freqs[0][0], freqs[1][0])
    else:
        print('NO')

main()
