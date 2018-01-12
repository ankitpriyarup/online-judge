def is_prime(x):
    if x % 2 == 0: return False
    for i in range(3, x, 2):
        if i * i > x:
            return True
        if x % i == 0:
            return False

    return True

def main():
    ans = 0
    for p in range(109300, 126301, 17):
        if not is_prime(p):
            ans += 1

    print(ans)

main()
