def is_prime(x):
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    for i in range(3, x, 2):
        if i * i > x:
            break
        if x % i == 0:
            return False

    return True

def main():
    n = int(input())
    if is_prime(n):
        print(1)
    elif n % 2 == 0:
        print(2)
    else:
        print(2 if is_prime(n - 2) else 3)

main()
