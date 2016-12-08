from collections import Counter
import hashlib

def main():
    inp = 'reyedfim'
    out = []

    c = 0
    while len(out) < 8:
        m = hashlib.md5()
        key = inp + str(c)
        m.update(key.encode('utf-8'))
        h = m.hexdigest()
        if h.startswith('00000'):
            out.append(h[5])
            print(c, h[5])

        c += 1

    print(''.join(out))



main()
