a = [int(input()) for _ in range(3)]
print(max(sum(a), (a[0] + a[1]) * a[2], a[0] * (a[1] + a[2]), a[0] * a[1] * a[2]))
