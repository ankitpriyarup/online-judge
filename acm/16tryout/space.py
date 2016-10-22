def done(l):
    for i in range(1, len(l)):
        if (l[i - 1] + 1) == l[i]:
            return False

    return True

t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    l.sort()

    ol = l

    while not done(l):
        nl = []
        for i in range(n):
            on_left = i > 0 and (l[i - 1] + 1) == l[i]
            on_right = i < (n - 1) and (l[i] + 1) == l[i + 1]

            if on_left == on_right:
                nl.append(l[i])
            elif on_left:
                nl.append(l[i] + 1)
            elif on_right:
                nl.append(l[i] - 1)

        for i in range(1, n):
            if nl[i] == nl[i - 1]:
                nl[i - 1] = l[i - 1]
                nl[i] = l[i]

        l = nl

    ans = max(abs(l[x] - ol[x]) for x in range(n))
    print(ans)
