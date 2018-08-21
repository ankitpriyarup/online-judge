from collections import Counter

def main():
    c = Counter(input()) + Counter(input())
    odd = 0
    for x in c:
        if c[x] % 2 == 1:
            odd += 1
    print('YES' if odd <= 1 else 'NO')


main()
