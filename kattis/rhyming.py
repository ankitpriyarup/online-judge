def main():
    word = input()
    e = int(input())
    rhymes = set()

    for _ in range(e):
        ends = input().split()
        if any(word.endswith(end) for end in ends):
            for end in ends:
                rhymes.add(end)

    p = int(input())
    for _ in range(p):
        line = input()
        if any(line.endswith(end) for end in rhymes):
            print('YES')
        else:
            print('NO')


main()
