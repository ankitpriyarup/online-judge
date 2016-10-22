t = int(input())
for _ in range(t):
    a, f = map(int, input().split())
    flights = [[] for _ in range(a)]
    for _ in range(f):
        c1, c2 = map(int, input().split())
        flights[c1].append(c2)

    ans = 0
    solved = True
    for x in range(a):
        if not solved:
            break
        for y in range(a):
            if not solved:
                break
            set1 = set([x])
            set2 = set([y])
            n = 0
            while not set1.intersection(set2):
                changed = False

                news1 = set([x for x in set1])
                for city in set1:
                    for dest in flights[city]:
                        if dest not in news1:
                            news1.add(dest)
                            changed = True

                news2 = set([x for x in set2])
                for city in set2:
                    for dest in flights[city]:
                        if dest not in news2:
                            news2.add(dest)
                            changed = True

                set1 = news1
                set2 = news2

                n += 1
                if not changed:
                    n = -1
                    break

            if n == -1:
                solved = False
                break

            ans = max(ans, n)

    if not solved:
        print("IMPOSSIBLE")
    else:
        print(ans)
