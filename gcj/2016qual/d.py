def main():
    T = int(input())
    for case_num in range(1, T + 1):
        K, C, S = map(int, input().split())
        ans = range(1, K ** C + 1, K ** (C - 1))
        print("Case #{0}: {1}".format(case_num, ' '.join(map(str, ans))))

main()
