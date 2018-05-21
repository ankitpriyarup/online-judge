def sum_dig(x):
    return sum(int(c) for c in str(x))

def main():
    l = int(input())
    d = int(input())
    x = int(input())
    mn = d + 1
    mx = l - 1
    for y in range(l, d + 1):
        if sum_dig(y) == x:
            mn = min(mn, y)
            mx = max(mx, y)
    print(mn)
    print(mx)

main()
