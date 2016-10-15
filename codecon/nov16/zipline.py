def main():
    n = int(input())
    hills = []
    for i in range(n):
        height = int(input())
        hills.append((height, i))

    hills.sort(key=lambda x: x[0])

    ans = []
    for i in range(n):
        best = 0
        for j in range(i):
            if abs(hills[i][1] - hills[j][1]) <= 2 and hills[j][0] < hills[i][0]:
                best = max(best, ans[j] + 1)
        ans.append(best)

    print(max(ans))


main()
