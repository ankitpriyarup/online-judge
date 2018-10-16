n = int(input())
a = list(input().split())
valid = all(a[i] == 'mumble' or a[i] == str(i + 1) for i in range(n))
print('makes sense' if valid else 'something is fishy')
