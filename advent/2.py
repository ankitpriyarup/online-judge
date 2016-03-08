def wrapping(a, b, c):
    return 2 * (a*b + a*c + b*c) + min(a*b, a*c, b*c)

def ribbon(a, b, c):
    return min(2 * a + 2 * b, 2 * a + 2 * c, 2 * b + 2 * c) + a * b * c

def main():
    fin = open('2.in', 'r')

    total_wrapping = 0
    total_ribbon = 0

    for line in fin.readlines():
        data = [int(x) for x in line.split('x')]
        total_wrapping += wrapping(*data)
        total_ribbon += ribbon(*data)

    fin.close()

    print "Part 1", total_wrapping
    print "Part 2", total_ribbon

if __name__ == '__main__':
    main()
