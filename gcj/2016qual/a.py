def main():
    T = int(input())
    for case_num in range(1, T + 1):
        N = int(input())

        if N == 0:
            print("Case #{0}: INSOMNIA".format(case_num))
            continue

        seen = [False] * 10
        ans = -1
        for i in range(1, 100):
            s = str(i * N)
            for c in s:
                seen[int(c)] = True

            if all(seen):
                ans = i * N
                break

        print("Case #{0}: {1}".format(case_num, ans))

main()
