b, k, g = map(int, input().split())
groups = k // g
ans = (b + groups - 2) // groups
print(ans)
