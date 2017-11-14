from __future__ import division, print_function
from fractions import Fraction
from collections import defaultdict

# row reduces an augmented matrix.
def rref(mat):
    n = len(mat)
    m = len(mat[0])

    start = 0
    for i in range(n):
        # find a pivot
        for row in range(start, n):
            if mat[row][i] != 0:
                pivot = row
                break
        else:
            continue

        mat[start], mat[pivot] = mat[pivot], mat[start]

        # scale this row
        val = mat[start][i]
        for j in range(m):
            mat[start][j] /= val 

        # remove this col in other rows
        for k in range(n):
            if k == start: continue
            scale = mat[k][i]
            mat[k] = [kv - scale * sv for kv, sv in zip(mat[k], mat[start])]

        start += 1

    return mat

def main():
    dice = []
    for _ in range(3):
        row = list(map(int, input().split()))
        if sum(row) == 0:
            return False

        dice.append(row)

    target = list(map(int, input().split()))
    dice = [[Fraction(x, 10000) for x in row] for row in dice]
    mat = [[dice[j][i] for j in range(3)] for i in range(3)]

    target = [Fraction(x, 10000) for x in target]
    aug = [mat[row] + [target[row]] for row in range(3)]
    simp = rref(aug)

    rank = sum(1 for row in simp if sum(row[:-1]) != 0)

    # print(dice)
    # print(mat)
    # print(target)
    # print(simp)
    # print(rank)

    if rank == 1:
        print('YES' if target in dice else 'NO')
    elif rank == 2:
        # t v1 + (1 - t)v2 = target
        # v1 + t (v2 - v1) = target
        valid = False
        for i in range(3):
            for j in range(3):
                if i == j:
                    continue
                # t * mat[0][i] + (1 - t) * mat[0][j] = target[0]
                # t * mat[0][i] + mat[0][j] - t * mat[0][j] = target[0]
                # t * mat[0][i] - t * mat[0][j] = target[0] - mat[0][j]
                # t * (mat[0][i] - mat[0][j]) = target[0] - mat[0][j]
                # t = (target[0] - mat[0][j]) / (mat[0][i] - mat[0][j])

                # Verify this holds for each row
                things = []
                for row in range(3):
                    slope = None if mat[row][i] == mat[row][j] else (target[row] - mat[row][j]) / (mat[row][i] - mat[row][j])
                    if slope is not None:
                        things.append(slope)

                valid |= all(0 < slope < 1 for slope in things) and (len(set(things)) == 1)
                # if valid:
                #     print(i, j, things)
        print('YES' if valid else 'NO')
    else:
        if all(row[-1] > 0 for row in simp):
            print('YES')
        else:
            print('NO')

    return True

while True:
    res = main()
    if not res:
        break
    input()
