n = int(input())
x = (bin(n)[2:])[::-1]
print(int(x, 2))
