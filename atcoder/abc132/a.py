s = input()
s = sorted(s)
valid = s[0] == s[1] and s[1] != s[2] and s[2] == s[3]
print('Yes' if valid  else 'No')
