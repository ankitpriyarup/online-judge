def main():
    prev = 'a'
    valid = True
    n, m = map(int, input().split())
    for _ in range(n):
        row = input()
        if any(c != row[0] for c in row):
            valid = False
        valid = valid and (row[0] != prev)
        prev = row[0]

    print('YES' if valid else 'NO')


main()
