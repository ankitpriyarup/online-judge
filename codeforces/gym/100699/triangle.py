def main():
    n = int(input())
    padding = n - 1
    middle = 0
    for i in range(n):
        out = [' ' * padding, '/', ' ' * middle, "\\"]
        print(''.join(out))
        padding -= 1
        middle += 2

main()
