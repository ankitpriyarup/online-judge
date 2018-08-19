def main():
    s = input()
    k = int(input()) - 1
    n = len(s)
    for i in range(n):
        if k == 0 or s[i] != '1':
            print(s[i])
            return
        k -= 1

main()
