from collections import Counter

def main():
    c = Counter(map(int, input().split()))
    if c[1] >= 1 or c[2] >= 2 or c[3] >= 3 or (c[4] == 2 and c[2] == 1):
        print('YES')
    else:
        print('NO')

main()
