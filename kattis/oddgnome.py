T = int(input())
for _ in range(T):
    a = list(map(int, input().split()))
    a = a[1:]
    ans = 1
    for i in range(1, len(a)):
        if a[i] != a[i - 1] + 1:
            ans = i

    print(ans)
