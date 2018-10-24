from functools import cmp_to_key

def my_cmp(x, y):
    a = x + y
    b = y + x
    if a == b:
        return 0
    elif a > b:
        return -1
    else:
        return 1

n = int(input())
a = [input() for _ in range(n)]
a.sort(key=cmp_to_key(my_cmp))
print(''.join(a))
