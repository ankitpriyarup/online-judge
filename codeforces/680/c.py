import sys

def main():
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]
    squares = [4, 9, 25, 49]
    pf = 0
    is_square = False
    for x in primes:
        print(x)
        sys.stdout.flush()
        resp = input()
        if resp == "yes":
            pf += 1

    for x in squares:
        print(x)
        sys.stdout.flush()
        resp = input()
        if resp == "yes":
            is_square = True
            break

    if is_square or pf > 1:
        print("composite")
    else:
        print("prime")

main()
