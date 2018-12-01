import hashlib

key = b'yzbqklnj'

x = 0
while True:
    m = hashlib.md5()
    m.update(key + bytes(str(x)))
    if m.hexdigest().startswith('000000'):
        print(x)
        break
    x += 1
