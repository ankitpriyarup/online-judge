def is_dark(h, a, b, hr):
    x = hr % h
    if a < b:
        return x <= a or x >= b
    else:
        return b <= x and x <= a

def main():
    n = int(input())
    max_h = -1
    planets = []
    for _ in range(n):
        h, a, b = map(int, input().split())
        planets.append((h, a, b))
        max_h = max(max_h, h)

    for hour in range(1825 * max_h):
    # for hour in range(max_h):
        dark = True
        for i in range(n):
            day_len, a, b = planets[i]
            dark = dark and is_dark(day_len, a, b, hour)

        if dark:
            print(hour)
            return
    print('impossible')

main()
