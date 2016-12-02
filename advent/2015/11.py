import sys

def valid(password):
    if 'i' in password or 'o' in password or 'l' in password:
        return False

    has_double = False
    has_run = False

    for c in "abcdefghijklmnopqrstuvwxyz":
        run = "" + c + chr(ord(c) + 1) + chr(ord(c) + 2)
        if run in password:
            has_run = True

    for c in "abcdefghijklmnopqrstuvwxyz":
        for d in "abcdefghijklmnopqrstuvwxyz":
            if c == d: continue
            d1 = c + c
            d2 = d + d
            if d1 in password and d2 in password:
                has_double = True

    return has_double and has_run

def inc(password):
    pos = len(password) - 1
    while password[pos] == 'z':
        pos -= 1
    new = chr(ord(password[pos]) + 1) 
    if new == 'i' or new == 'o' or new == 'l':
        new = chr(ord(new) + 1)

    return password[:pos] + new + 'a' * len(password[(pos + 1):])

def main():
    password = 'cqjxxyzz'
    while not valid(password):
        password = inc(password)

    print "Part 1", password
    password = inc(password)
    while not valid(password):
        password = inc(password)

    print "Part 2", password

if __name__ == '__main__':
    main()
