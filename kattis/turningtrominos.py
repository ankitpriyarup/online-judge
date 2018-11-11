#!/usr/bin/env python3

def in_corner(x, y, half, quart):
    return (x < half and y < quart) or (x < quart and y < half)

def in_center(x, y, half, quart):
    return x >= quart and y >= quart and in_corner(x - quart, y - quart, half, quart)

def main():
    x, y = map(int, input().split())
    half = 1 << 62
    orientation = 0
    while half >= 2:
        quart = half >> 1
        if in_corner(x, y, half, quart):
            # bottom left
            pass
        elif in_center(x, y, half, quart):
            x -= quart
            y -= quart
        elif x >= half:
            # bottom right
            orientation += 3
            x -= half
            # rotate about center
            x, y = y, half - 1 - x
        else:
            # top left
            orientation += 1
            y -= half
            # rotate about center
            x, y = half - 1 - y, x

        half = quart

    orientation %= 4
    print(orientation)


T = int(input())
for _ in range(T):
    main()
