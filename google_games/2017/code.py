data = {
'A': 'Banana',
'B': 'Mike',
'C': 'Monkey',
'D': 'Courtney',
'E': 'Jerome',
'F': 'Scissors',
'G': 'Turkey',
'H': 'Apple',
'I': 'Duck',
'J': 'Tissue',
'K': 'Hat',
'L': 'Zombie',
'M': 'Chair',
'N': 'Bond',
'O': 'Keyboard',
'P': 'Koala',
'Q': 'Bee',
'R': 'Sword',
'S': 'Wall',
'T': 'Gold',
'U': 'Backpack',
'V': 'Tower',
'W': 'Shelf',
'X': 'Mary',
'Y': 'Foam',
'Z': 'Arbitrage'}

for k in data:
    data[k] = data[k].upper()

def shift(c, v):
    c = ord(c)
    c -= ord('A')
    c -= v

    if c < 0:
        c += 26
    return (chr(c + ord('A')))

'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def main():
    """
    s = 'Q'
    new = ''.join(data[c] for c in s)
    print(new)

    blah = []
    for i, c in enumerate(new):
        if i == 0 or c != new[i - 1]:
            blah.append(c)

    print(blah)

    blah[1] = shift(blah[1], 7)
    blah = ''.join(blah)
    print(blah)

    new = ''.join(data[c] for c in blah)
    print(new)

    new = new[-1] + new[:-1]
    print(new)

    blah = ''.join(shift(c, 26 - 5) for c in new)
    print(blah)

    new = list('DRRFW')
    print(new)
    new[0] = shift(new[0], 25)
    new[1] = shift(new[1], 25)
    new[3] = shift(new[3], 1)
    new[4] = shift(new[4], 1)
    print(new)
    print(''.join(new))
    """

    val = 'REVERSE'

    print(val)
    val = val[2:]
    print(val)
    val = val[:-1] + val[-1] + ''.join(reversed(val[:-1]))
    print(val)
    val = list(val)
    print(val)

    for i in range(4):
        val[i] = shift(val[i], 24)

    for i in range(5, 9):
        val[i] = shift(val[i], 2)

    val = (''.join(val))
    print(val)

    val = 'XGTT'
    print(val)

    val = ''.join(shift(c, 26 - 5) for c in val)

    print(val)

    val = val[-1] + val[:-1]

    print(val)
    val = 'YY'

    print(val)

    val = val[0] + shift(val[1], 7)
    print(val)

main()
