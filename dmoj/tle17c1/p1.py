def main():
    s = list(input())
    n = len(s)
    for i in range(n - 1, -1, -1):
        if 'a' <= s[i] <= 'm':
            s[i] = 'a'
            break
        else:
            s[i] = 'a'
            if i == 0:
                s = ['a'] + s
                break
            elif s[i - 1] != 'z':
                s[i - 1] = chr(ord(s[i - 1]) + 1)
                break

    print(''.join(s))

main()
