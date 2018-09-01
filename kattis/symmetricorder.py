def main(tc):
    n = int(input())
    if n == 0:
        return False

    names = [input() for _ in range(n)]
    evens = list(range(0, n, 2))
    odds = list(reversed(range(1, n, 2)))
    print('SET', tc)
    for x in evens:
        print(names[x])
    for x in odds:
        print(names[x])

    return True

tc = 1
while main(tc):
    tc += 1
