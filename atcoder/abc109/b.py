n = int(input())
w = [input() for _ in range(n)]
valid = len(w) == len(set(w))
for i in range(1, n):
    valid &= w[i][0] == w[i - 1][-1]
print('Yes' if valid else 'No')
