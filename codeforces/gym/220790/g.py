p, ap, ag, sp, sg, g = map(int, input().split())

ans = 0
for armor in range(1000):
    if ap * armor > p:
        break

    for sword in range(1000):
        if ap * armor + sp * sword > p:
            break

        left = p - (ap * armor + sp * sword)
        gold = armor * ag + sword * sg + left * g
        ans = max(ans, gold)

print(ans)
