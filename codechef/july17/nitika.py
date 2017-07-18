def solve():
    words = input().split()
    words = [word.lower() for word in words]

    out = ''
    for name in words[:-1]:
        out += (name[0].upper() + '. ')
    print(out + words[-1][0].upper() + words[-1][1:])

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()
