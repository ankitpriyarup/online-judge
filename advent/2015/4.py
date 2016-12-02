import hashlib

def prefix(salt, x):
    n = 1
    out = ''
    while not out.startswith(x):
        m = hashlib.md5()
        m.update(salt + str(n))
        out = m.hexdigest()
        n += 1

    return n - 1

def main():
    salt = "yzbqklnj"
    print "Part 1", prefix(salt, '00000')
    print "Part 2", prefix(salt, '000000')

if __name__ == '__main__':
    main()
