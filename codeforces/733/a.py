def main():
    s = input()
    s = 'A' + s + 'A'
    last = 0
    gap = 0
    for i in range(1, len(s)):
        if s[i] in "AEIOUY":
            gap = max(i - last, gap)
            last = i

    print(gap)

main()
