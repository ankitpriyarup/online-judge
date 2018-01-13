def main():
    vals = []
    for _ in range(3):
        vals.append(int(input()))

    poss = False
    for a in vals:
        for b in vals:
            for c in vals:
                if a + b == c:
                    poss = True

    print('YES' if poss else 'NO')

main()
