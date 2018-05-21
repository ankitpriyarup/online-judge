def main():
    n, T = map(int, input().split())
    a = list(map(int, input().split()))
    ptr = 0
    tt = 0
    while ptr < n and tt + a[ptr] <= T:
        tt += a[ptr]
        ptr += 1
    print(ptr)

main()
