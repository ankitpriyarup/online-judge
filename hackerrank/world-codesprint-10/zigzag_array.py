def minimum_deletions(a):
    ptr = 1
    score = 0

    while ptr < len(a) - 1:
        if a[ptr - 1] <= a[ptr] <= a[ptr + 1] or a[ptr - 1] >= a[ptr] >= a[ptr + 1]:
            a = a[:ptr] + a[ptr + 1:]
            score += 1
        else:
            ptr += 1

    return score

n = int(input())
a = list(map(int, input().split()))

result = minimum_deletions(a)
print(result)
