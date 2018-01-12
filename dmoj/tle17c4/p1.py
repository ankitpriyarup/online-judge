def can_pass(x, k, n):
    return (x + k) * 1000 >= n * 595

def main():
    m, k, n = map(int, input().split())
    for i in range(m + 1):
        if can_pass(i, k, n):
            print(i)
            return

    print('have mercy snew')

main()
