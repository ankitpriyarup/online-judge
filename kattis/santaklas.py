from math import cos, sin
import sys

def main():
    h, v = map(int, sys.stdin.readline().split())
    if v <= 180:
        print('safe')
    else:
        v -= 180
        ans = h / sin(v / 180.0 * 3.141592653589)
        print(int(ans))

main()
