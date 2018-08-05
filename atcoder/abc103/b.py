def main():
    s = input()
    t = input()
    n = len(s)
    for i in range(n):
        ss = s[i:] + s[:i]
        if ss == t:
            print('Yes')
            return
    print('No')

main()
