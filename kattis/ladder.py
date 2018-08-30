from math import sin, ceil
pi = 3.1415926535897
h, v = map(int, input().split())
print(ceil(h / sin(pi * v / 180.0)))
