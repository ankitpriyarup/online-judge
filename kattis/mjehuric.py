a = list(input().split())
while a != ['1', '2', '3', '4', '5']:
    for i in range(4):
        if a[i] > a[i + 1]:
            a[i], a[i + 1] = a[i + 1], a[i]
            print(' '.join(a))
