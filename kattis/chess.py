def shared(a, b):
    return (a[0] - a[1] == b[0] - b[1]) or (a[0] + a[1] == b[0] + b[1])

def to_col(x):
    return chr(ord('A') + x)

def to_row(x):
    return str(8 - x)

def parse(a, b):
    col = ord(a) - ord('A')
    row = 8 - int(b)

    return (row, col)

def main():
    q = int(input())
    for _ in range(q):
        pos = list(input().split())
        a = parse(pos[0], pos[1])
        b = parse(pos[2], pos[3])

        if a == b:
            print(0, pos[0], pos[1])
        elif shared(a, b):
            pos = [1] + pos
            print(*pos)
        else:
            found = False
            for i in range(8):
                if found:
                    break

                for j in range(8):
                    p = (i, j)
                    if shared(a, p) and shared(p, b):
                        found = True
                        print(2, pos[0], pos[1], to_col(j), to_row(i), pos[2], pos[3])
                        break
            if not found:
                print('Impossible')

main()
