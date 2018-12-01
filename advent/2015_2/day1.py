inp = input()

x = 0
for i, c in enumerate(inp):
    if c == '(':
        x += 1
    else:
        x -= 1
    if x == -1:
        print(i + 1)
        break
