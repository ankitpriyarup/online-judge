def convert(x):
    def pm(c):
        return '+' if c == '1' else '-'

    return map(pm, bin(x)[2:])

for x in range(1, 2 ** 11):
    print(''.join(list(convert(x))))
