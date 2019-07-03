s = input()
n = len(s)
a = sum(c == 'o' for c in s)
print('YES' if ((15 - n) + a) >= 8 else 'NO')
