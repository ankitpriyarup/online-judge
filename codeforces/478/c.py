r, g, b = map(int, input().split())
l = sorted([r, g, b])
print(min(sum(l) // 3, l[0] + l[1]))
