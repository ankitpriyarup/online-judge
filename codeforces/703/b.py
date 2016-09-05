n, k = map(int, input().split())
c = list(map(int, input().split()))
capitals = set(map(lambda x: int(x) - 1, input().split()))

total_beauty = sum(c)
capital_beauty = sum(c[x] for x in capitals)
ans = 0

for i in range(n):
    if i in capitals:
        ans += c[i] * (total_beauty - c[i])
    else:
        before = n - 1 if i == 0 else i - 1
        after = 0 if i == n - 1 else i + 1

        if before not in capitals:
            ans += c[before] * c[i]
        if after not in capitals:
            ans += c[after] * c[i]

        ans += capital_beauty * c[i]

print(ans // 2)
