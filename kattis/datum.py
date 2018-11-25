d, m = map(int, input().split())
days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
d -= 1
m -= 1
dow = 3

dd = 0
mm = 0
while dd != d or mm != m:
    dd += 1
    dow = (dow + 1) % 7
    if dd == days[mm]:
        mm += 1
        dd = 0

names = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
print(names[dow])

