from collections import Counter
def main():
    n, m = map(int, input().split())
    c = Counter()
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            c[i + j] += 1
    ans = c.most_common()[0][1]
    out = [x for x in c if c[x] == ans]
    out.sort()
    for x in out:
        print(x)

main()
