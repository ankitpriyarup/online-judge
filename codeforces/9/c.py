def main():
    ans = 0
    n = int(input())
    for mask in range(1, 1 << 10):
        s = int(bin(mask)[2:])
        if s <= n:
            ans += 1
    print(ans)

main()
