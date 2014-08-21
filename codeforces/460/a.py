'''
n, m = map(int, raw_input().split())

days = n
while n > 0:
    n = n / m
    days += n

print days
'''

n, m = map(int, raw_input().split())
days = 0
socks = n
while socks > 0:
    socks -= 1
    days += 1
    if days % m == 0:
        socks += 1

print days
