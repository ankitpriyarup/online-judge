n = int(input())
a = list(map(int, input().split()))
a.sort()
if sum(a[:-1]) > a[-1]:
    print('Yes')
else:
    print('No')
