def main():
    n = int(input())
    s = set([input() for _ in range(n)])
    print(len(s))

T = int(input())
for _ in range(T):
    main()
