from fractions import Fraction

def compute(vp, vd, t):
    # vp * x = vd * (x - t)
    # vp * x = vd * x - vd * t
    # vd * t = (vd - vp) * x
    # x = vd * t / (vd - vp)

    return Fraction(t * vd, vd - vp)

def main():
    vp = int(input())
    vd = int(input())
    t = int(input())
    f = int(input())
    c = int(input())

    if vp >= vd:
        print(0)
        return

    # first intersection at time x
    # vp * x = vd * (x - t)
    # vp * x = vd * x - vd * t
    # (vp - vd) *x = - vd * t
    # x = vd * t / (vd - vp)

    goal_time = Fraction(c, vp)
    delay = t
    b = 0
    intersection = compute(vp, vd, delay)

    # print(delay, intersection, goal_time)
    while intersection < goal_time:
        b += 1
        delay += f + 2 * (intersection - delay)
        intersection = compute(vp, vd, delay)

        # print(delay, intersection, goal_time)

    print(b)

main()
