def main():
    n = int(input())
    s = input()
    for d in range(2, n + 1):
        if n % d == 0:
            s = ''.join(reversed(s[:d])) + s[d:]

    print(s)

main()
