def main():
    ans = []
    n = int(input())
    for i in range(1, n + 1):
        vals = list(map(int, input().split()))
        good = (1 not in vals) and (3 not in vals)
        if good:
            ans.append(str(i))

    print(len(ans))
    print(' '.join(ans))
main()
