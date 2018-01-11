def main():
    s = input()
    n = len(s)
    works = True
    for i in range(1, n):
        if s[i - 1] == s[i]:
            works = False
            break

    print('Odd.' if works else 'Or not.')

main()
