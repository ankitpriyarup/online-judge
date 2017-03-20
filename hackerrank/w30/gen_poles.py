from random import randint
def main():
    n = 5000
    k = 3000
    print(n, k)
    for i in range(n):
        x, w = randint(20 * i, 20 * i + 19), randint(1, 1e6)
        print(x, w)

main()
