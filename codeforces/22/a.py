n = int(input())
a = list(map(int, input().split()))
a.sort()
if a[0] == a[-1]:
    print('NO')
else:
    j = 1
    while a[0] == a[j]:
        j += 1
    print(a[j])
