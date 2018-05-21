def main():
    n, r = map(int, input().split())
    s = set(int(input()) for _ in range(r))
    x = 1
    while x <= n and x in s:
        x += 1
    if x > n:
        print('too late')
    else:
        print(x)

main()
