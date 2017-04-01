def main():
    n, v = map(int, input().split())
    out = []
    for i in range(n):
        s = list(map(int, input().split()))
        s = s[1:]
        if min(s) < v:
            out.append(i + 1)

    print(len(out))
    print(' '.join(str(x) for x in out))

main()
