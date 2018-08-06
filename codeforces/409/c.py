def main():
    a = list(map(int, input().split()))
    assert(len(a) == 5)
    z = [1, 1, 2, 7, 4]
    ans = min(x // y for x, y in zip(a, z))
    print(ans)

main()
