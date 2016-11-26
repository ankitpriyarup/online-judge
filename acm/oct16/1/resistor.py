valid = [10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82]
name = ['black', 'brown', 'red', 'orange', 'yellow', 'green', 'blue', 'violet', 'gray', 'white']

def solve(resistance):
    best_diff = float('inf')
    best_coeff = valid[0]
    best_exp = 0

    base = 1
    for third in range(0, 12):
        for coeff in valid:
            val = base * coeff
            diff = abs(resistance - val)
            if diff <= best_diff:
                best_diff = diff
                best_coeff = coeff
                best_exp = third

        base *= 10

    print(name[best_c // 10], name[best_c % 10], name[best_exp])


def main():
    T = int(input())
    for _ in range(T):
        solve(int(input()))

main()
