n = int(input())
x = n % 10
if x > 5:
    n += 10

n -= x

print(n)
