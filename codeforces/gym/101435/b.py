a = list(map(int, input().split()))
works = False
s = sum(a)
for i in range(4):
    for j in range(i + 1, 4):
        if a[i] + a[j] == s - a[i] - a[j]:
            works = True

print('Yes' if works else 'No')
