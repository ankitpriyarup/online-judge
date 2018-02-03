import itertools

def do_flips(perm, flip):
    for i in range(3):
        if (flip & (1 << i)) > 0:
            yield (perm[i][1], perm[i][0])
        else:
            yield perm[i]

def main():
    sizes = [tuple(sorted(int(x) for x in input().split())) for _ in range(3)]
    target = max(rect[1] for rect in sizes)

    if all(rect[1] == target for rect in sizes) and sum(rect[0] for rect in sizes) == target:
        print('YES')
        return

    for perm in itertools.permutations(sizes):
        for f in range(8):
            res = list(do_flips(perm, f))
            if res[0][0] == target and res[1][1] == res[2][1] and res[0][1] + res[1][1] == target and res[1][0] + res[2][0] == target:
                print('YES')
                return

    print('NO')

main()
