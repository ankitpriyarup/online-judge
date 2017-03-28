def get_name(i):
    first = i // 26
    second = i % 26
    return chr(first + ord('A')) + chr(second + ord('a'))

def main():
    n, k = map(int, input().split())
    commands = input().split()

    names = [get_name(i) for i in range(k)]
    if commands[0] == "NO":
        names[0] = names[1]

    ptr = 1
    next_id = k + 1
    for c in commands[1:]:
        if c == "YES":
            names.append(get_name(next_id))
            next_id += 1
        else:
            names.append(names[ptr])

        ptr += 1

    print(' '.join(names))

main()
