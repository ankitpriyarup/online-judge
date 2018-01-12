def main():
    n = int(input())
    simon = 'Simon says'
    for _ in range(n):
        s = input()
        if s.startswith(simon):
            print(s[len(simon):])

main()
