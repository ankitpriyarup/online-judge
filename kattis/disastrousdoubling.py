MOD = int(1e9 + 7)

def main():
    n = int(input())
    b = map(int, input().split())

    cur = 1
    for x in b:
        cur <<= 1

        if x > cur:
            cur = -1
            break

        cur -= x

    if cur < 0:
        print('error')
    else:
        print(cur % MOD)

main()
