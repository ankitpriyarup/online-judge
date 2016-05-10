n = int(input())
s = input()

i = 1
ans = 0
while i < n - 1:
    if s[(i - 1):(i + 2)] == '010':
        ans += 1
        i += 3
    else:
        i += 1

print(ans)
