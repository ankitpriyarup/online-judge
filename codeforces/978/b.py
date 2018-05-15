n = int(input())
s = input()
stk = []
ans = 0
for c in s:
    if c == 'x' and len(stk) >= 2 and stk[-2] == 'x' and stk[-1] == 'x':
        ans += 1
    else:
        stk.append(c)

print(ans)
