def main():
    n = int(input())
    last_time = -1
    repeats = 0
    days = 1
    for _ in range(n):
        line = input()
        e = line.index(']')
        line = line[1:e]
        h = int(line[:2])
        m = int(line[3:5])
        h %= 12
        if line[6] == 'p':
            h += 12
        time = 60 * h + m
        if time < last_time or (time == last_time and repeats == 10):
            days += 1
            repeats = 1
        elif time == last_time:
            repeats += 1
        else:
            repeats = 1

        last_time = time

    print(days)

main()
