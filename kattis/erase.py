x = int(input())
a = input()
b = input()
d = x % 2
n = len(a)
works = all(int(a[i]) ^ int(b[i]) == d for i in range(n))
print('Deletion succeeded' if works else 'Deletion failed')
