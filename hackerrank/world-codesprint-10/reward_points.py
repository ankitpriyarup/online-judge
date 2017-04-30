def getPoints(months):
    return sum(min(100, 10 * x) for x in months)

months = list(map(int, input().split()))
print(getPoints(months))
