def dragon(a):
    flip = {'0': '1', '1': '0'}
    b = ''.join(flip[x] for x in reversed(a))
    return str(a) + '0' + str(b)


def checksum(c):
    out = []
    for i in range(0, len(c), 2):
        out.append('1' if c[i] == c[i + 1] else '0')

    if len(out) % 2 == 0:
        return checksum(''.join(out))
    else:
        return ''.join(out)


def main():
    inp = '01111010110010011'
    out_len = 35651584
    """
    inp = '10000'
    out_len = 20
    """

    while len(inp) < out_len:
        inp = dragon(inp)

    inp = inp[:out_len]
    # print(inp)

    csum = checksum(inp)
    print(csum)


main()
