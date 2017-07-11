def solve(x):
    while not (x % 8 == 0 or x % 5 == 0):
        x += 1

    return x

def main():
    # number of cards needed
    # 2, 7, 15
    # Height h requires 3 * h * (h + 1) / 2 - h
    # You have h * (h + 1) / 2 triangles, but remove the base
    # Expanding this gives you 3 * h^2 / 2 + 3 * h / 2 - h
    # Expanding this gives you 1/2 (3 * h^2 + h)
    # This needs to be divisible by 4, so (3 * h^2 + h)
    # needs to be divisible by 8
    # l = [(x, (3 * x * x + x) % 8) for x in range(10)]
    # print(l)
    # h is either 0 or 5 mod 8
    # luckily the divisibility rules for these are simple
    n = int(input())
    while n % 8 != 5 and n % 8 != 0:
        n += 1

    print(n)

main()
