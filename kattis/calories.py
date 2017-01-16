def parse_line(line):
    CONVERSION = [9, 4, 4, 4, 7]
    strs = line.split()
    percents = 0
    ret = [0] * 5

    for i, amount in enumerate(strs):
        num, suffix = int(amount[:-1]), amount[-1]
        if suffix == '%':
            percents += num
        elif suffix == 'g':
            ret[i] = CONVERSION[i] * num
        else:
            ret[i] = num

    remaining = 100 - percents
    cals_found = sum(ret)

    total_cals = 100 * cals_found / remaining

    for i, amount in enumerate(strs):
        num, suffix = int(amount[:-1]), amount[-1]
        if suffix == '%':
            ret[i] = num * total_cals / 100

    return ret

def main():
    while True:
        line = input()
        fat_cal = 0
        total_cal = 0

        while line != '-':
            values = parse_line(line)
            fat_cal += values[0]
            total_cal += sum(values)
            line = input()

        if total_cal == 0:
            break

        ans = 100 * fat_cal / total_cal
        print_ans = str(int(ans + 0.5))
        print(print_ans + '%')


main()
