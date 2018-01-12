import itertools

def main():
    rects = []
    for _ in range(3):
        w, h = map(int, input().split())
        rects.append((w, h))

    found = False
    for perm in itertools.permutations(rects):
        if found:
            break

        for subset in range(8):
            out = []
            for i in range(3):
                if (subset & (1 << i)) == 0:
                    out.append(perm[i])
                else:
                    out.append((perm[i][1], perm[i][0]))

            if out[0][0] == out[2][0] and out[0][0] == out[1][0] and sum(out[x][1] for x in range(3)) == out[0][0]:
                found = True

            if out[0][0] + out[1][0] == out[2][0] and out[0][1] == out[1][1] and out[0][1] + out[2][1] == out[2][0]:
                found = True


    print('YES' if found else 'NO')



main()
