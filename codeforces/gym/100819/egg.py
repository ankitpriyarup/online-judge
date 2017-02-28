def main():
    n, k = map(int, input().split())

    low_break = 2
    high_safe = k - 1

    for _ in range(n):
        floor, state = input().split()
        floor = int(floor)

        if state == "SAFE":
            low_break = max(low_break, floor + 1)
        else:
            high_safe = min(high_safe, floor - 1)

    print(low_break, high_safe)

main()
