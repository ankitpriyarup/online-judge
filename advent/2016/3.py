def main():
    fin = open('3.in', 'r')
    count = 0
    for line in fin:
        a = list(map(int, line.strip().split()))
        a.sort()
        if a[0] + a[1] > a[2]:
            count += 1
    print(count)


main()
