q = int(input())
for _ in range(q):
    l1, r1, l2, r2 = map(int, input().split())
    printed = False
    for x in [l1, r1]:
        for y in [l2, r2]:
            if x != y:
                if not printed:
                    print(x, y)
                printed = True
                break
