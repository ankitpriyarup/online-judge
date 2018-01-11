n = int(input())
a = list(map(int, input().split()))
a.sort()

i = 0
bought = 0
while i < n:
    price = a[i] + 1
    bought += 1
    i += 1
    if i < n and abs(price - a[i]) <= 1:
        i += 1

print(bought)
