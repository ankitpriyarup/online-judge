def solve(n, k):
    left_size = n // 2
    right_size = n // 2
    if n % 2 == 0:
        left_size -= 1

    if k == 0:
        return (right_size, left_size)
    else:
        # interspersed left right left right
        if k % 2 == 1:
            return solve(right_size, (k - 1) // 2)
        else:
            return solve(left_size, (k - 1) // 2)

def main():
    t = int(input())
    for tt in range(t):
        n, k = map(int, input().split())
        a, b = solve(n, k - 1)
        print('Case #{}: {} {}'.format(tt + 1, a, b))

main()
