def main():
    n, k = map(int, input().split())

    cost = k
    after = 5
    ans = 0
    while ans < n and cost + after <= 240:
        cost += after
        ans += 1
        after += 5

    print(ans)

main()
