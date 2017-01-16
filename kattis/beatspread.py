def solve(s, d):
    """
    s = a + b
    d = a - b
    s + d = 2a
    a = (s + d) / 2
    """
    two_a = s + d
    if two_a % 2 != 0:
        return None
    a = two_a // 2
    b = s - a

    if a >= 0 and b >= 0:
        return (a, b)
    else:
        return None

def main():
    n = int(input())
    for _ in range(n):
        s, d = map(int, input().split())
        solution = None
        for sign in [-1, 1]:
            if solution is None:
                solution = solve(s, sign * d)

        if solution is None:
            print('impossible')
        else:
            print(max(solution), min(solution))

main()
