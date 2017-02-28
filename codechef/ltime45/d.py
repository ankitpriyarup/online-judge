from hypothesis import find
from hypothesis.strategies import sets, lists, integers

M = 2 ** 32
def sub(a, b):
    ans = a - b
    if ans < 0:
        ans += M

    return ans

def mul(a, b):
    return (a * b) % M

def bad_collinear(ax, ay, bx, by, cx, cy):
    return mul(sub(bx, ax), sub(cy, ay)) == mul(sub(by, ay), sub(cx, ax))

def good_collinear(ax, ay, bx, by, cx, cy):
    return (bx - ax) * (cy - ay) == (by - ay) * (cx - ax)

def target(l):
    cap = 490375
    good_shape = len(l) == 6 and all(0 <= x <= cap for x in l)
    return good_shape and good_collinear(*l) != bad_collinear(*l)

def main():
    pts = [(0, 0), (580981, 431795), (914958, 554338), (518360, 23016), (441824, 483616)]

    lo = 1
    cap = int(1e4)
    for x in range(lo, cap):
        for y in range(lo, cap):
            valid = True
            for i in range(5):
                for j in range(i + 1, 5):
                    ax, ay = pts[i]
                    bx, by = pts[j]
                    if not bad_collinear(ax, ay, bx, by, x, y) or good_collinear(ax, ay, bx, by, x, y):
                        valid = False

            if valid:
                print(x, y)

main()
