def to_min(time):
    ts = 0
    if time.endswith('p.m.'):
        ts += 60 * 12

    colon_pos = time.index(':')
    h = int(time[:colon_pos]) % 12
    m = int(time[colon_pos + 1:colon_pos + 3])
    ts += 60 * h
    ts += m

    return ts

def main():
    n = int(input())
    if n == 0:
        return False
    times = [input() for _ in range(n)]
    times.sort(key=to_min)
    for time in times:
        print(time)
    print()
    return True

while main():
    pass
