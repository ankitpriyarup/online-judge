def good(s):
    if s[0] != 'A':
        return False

    cocc = 0
    for x in range(2, len(s) - 1):
        if s[x] == 'C':
            cocc += 1

    if cocc != 1:
        return False

    s = s[1:]
    p = s.index('C')
    s = s[:p] + s[p + 1:]
    return all(c in 'abcdefghijklmnopqrstuvwxyz' for c in s)

def main():
    s = input()
    if good(s):
        print('AC')
    else:
        print('WA')

main()
