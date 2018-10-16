from collections import Counter

def can_make(e, n, x):
    return e >= x and (n - x) // 10 >= x

n = int(input())
e = sum(c == '8' for c in input())

ans = 0
while can_make(e, n, ans):
    ans += 1
print(ans - 1)
