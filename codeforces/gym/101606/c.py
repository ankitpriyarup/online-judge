n = int(raw_input())

v = {'red': 1, 'yellow': 2, 'green': 3, 'brown': 4, 'blue': 5, 'pink': 6, 'black': 7}
num_red = 0
max_val = 0
tot_val = 0

for i in range(n):
    c = raw_input()
    if c == 'red':
        num_red += 1
    va = v[c]
    max_val = max(max_val, va)
    tot_val += va

if num_red == n:
    print 1
else:
    print num_red * max_val + tot_val
