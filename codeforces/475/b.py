def main():
    n, m = map(int, input().split())
    a = input()
    b = input()

    valid = (a[0] == '>' and a[-1] == '<' and b[0] == '^' and b[-1] == 'v') \
         or (a[0] == '<' and a[-1] == '>' and b[0] == 'v' and b[-1] == '^')

    print("YES" if valid else "NO")

main()
