def main():
    a = list(map(int, input().split()))
    a.sort()
    s = 'ABC'
    t = input()

    out = [a[s.index(c)] for c in t]
    print(' '.join(str(x) for x in out))

main()
