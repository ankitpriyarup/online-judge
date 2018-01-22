def main():
    n = int(input())
    simon = 'simon says '
    for _ in range(n):
        s = input()
        if s.startswith(simon):
            print(s[len(simon):])
        else:
            print()

main()
