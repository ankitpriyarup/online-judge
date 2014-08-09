n = raw_input()
n = int(n[-2:]) if len(n) > 4 else int(n)
n = n % 4
print (4 if n == 0 else 0)
