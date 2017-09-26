def main():
    n = int(input())
    a = set(map(int, input().split()))
    if 1 in a:
        print(-1)
    else:
        print(1)

main()
