def scramble(block, p):
    return ''.join(block[x] for x in p)

def main():
    while True:
        a = list(map(int, input().split()))
        if a[0] == 0:
            break
        n = a[0]
        a = tuple(x - 1 for x in a[1:])

        s = input()
        while len(s) % n != 0:
            s += ' '

        out = []
        for i in range(0, len(s), n):
            block = s[i:i + n]
            out.append(scramble(block, a))

        print("'" + ''.join(out) + "'")

main()
