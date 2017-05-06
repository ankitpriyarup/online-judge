from collections import Counter

def main():
    n, q = map(int, input().split())
    c = Counter()
    for _ in range(q):
        u, v = map(int, input().split())
        c[u] += 1
        c[v] += 1

    safe = all(c[x] % 2 == 0 for x in c)
    print('YES' if safe else 'NO')

main()
