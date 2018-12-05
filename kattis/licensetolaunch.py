n = int(input())
a = list(map(int, input().split()))
x = min(a)
for i in range(n):
    if a[i] == x:
        print(i)
        break
