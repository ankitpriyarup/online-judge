import itertools

def main():
    v = list(map(int, input().split()))
    ans = 0

    for up, left, down, right in itertools.permutations(v):
        if up < down or left > right:
            continue

        ans = max(ans, down * left)

    print(ans)

main()
