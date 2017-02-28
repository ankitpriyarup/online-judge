def is_right_tri(t):
    a, b, c = t
    return a * a + b * b == c * c

def main():
    t1 = list(map(int, input().split()))
    t2 = list(map(int, input().split()))

    t1.sort()
    t2.sort()
    valid = t1 == t2 and is_right_tri(t1)

    print("YES" if valid else "NO")

main()
