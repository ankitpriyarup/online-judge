s = [(sum(map(int, input().split())), i) for i in range(5)]

su, i = max(s)
print(i + 1, su)
