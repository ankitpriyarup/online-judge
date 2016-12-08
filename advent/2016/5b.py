from collections import Counter
import hashlib

def main():
    inp = 'reyedfim'
    out = ['g'] * 8

    c = 0
    filled = 0
    while filled < 8:
        m = hashlib.md5()
        key = inp + str(c)
        m.update(key.encode('utf-8'))
        h = m.hexdigest()
        if h.startswith('00000'):
            pos = int(h[5], 16)
            val = h[6]

            if pos < 8 and out[pos] == 'g':
                filled += 1
                out[pos] = val
                print(c, h[5], h[6])

        c += 1

    print(''.join(out))



main()
