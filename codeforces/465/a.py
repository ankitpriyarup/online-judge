n = int(raw_input())
s = raw_input()
carry = 1
ans = 0
for i, e in enumerate(s):
    if carry == 0:
        break
    carry = 1 if (e == '1') else 0
    ans = i
print ans+1
