def main():
    count = 1
    summ = 1
    s = input()
    for c in s:
        if c == 'L':
            summ *= 2
        elif c == 'R':
            summ *= 2
            summ += count
        elif c == 'P':
            pass
        else:
            count, summ = 3 * count, 5 * summ + count

    print(summ)

main()
