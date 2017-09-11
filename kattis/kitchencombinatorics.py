INF = 1000000000000000000

def main():
    r, s, m, d, n = map(int, input().split())
    brands = list(map(int, input().split()))

    ingredients = []
    for _ in range(s + m + d):
        l = list(map(int, input().split()))
        cur = tuple([x - 1 for x in l[1:]])
        ingredients.append(cur)

    bad = set()
    for _ in range(n):
        a, b = map(int, input().split())
        a -= 1
        b -= 1

        bad.add((a, b))
        bad.add((b, a))

    ans = 0
    for i in range(s):
        for j in range(s, s + m):
            if (i, j) in bad:
                continue
            for k in range(s + m, s + m + d):
                if (i, k) in bad or (j, k) in bad:
                    continue

                used = set()
                for x in ingredients[i]:
                    used.add(x)
                for x in ingredients[j]:
                    used.add(x)
                for x in ingredients[k]:
                    used.add(x)

                cur = 1
                for x in used:
                    cur *= brands[x]

                ans += cur

    print('too many' if ans > INF else ans)

main()
