def main():
    n = int(input())

    lat = 0

    valid = True

    for _ in range(n):
        amount, direction = input().split()
        amount = int(amount)

        if lat == 0 and direction[0] != 'S':
            valid = False
        elif lat == 20000 and direction[0] != 'N':
            valid = False

        if direction[0] == 'S':
            lat += amount
        elif direction[0] == 'N':
            lat -= amount

        if 0 > lat or lat > 20000:
            valid = False

    print("YES" if valid and lat == 0 else "NO")


main()
