import math

n, k = map(int, raw_input().split())
f = map(int, raw_input().split())

ans = 0

while len(f) > 0:
    minfloor = min(f)
    # take everyone to minfloor, k people at a time
    trips = int(math.ceil(len(f) / (k + 0.0)))
    # for each trip, add the time to go up and down except for the last one
    time = (trips - 1)*(2*(minfloor - 1)) + (minfloor - 1)
    newf = [x-minfloor+1 for x in f if x-minfloor+1 > 1]
    f = newf
    ans += time + (minfloor - 1)

print ans
