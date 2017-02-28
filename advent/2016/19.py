def winner(x):
    if x <= 2:
        return 1
    if x % 2 == 0:
        a = winner(x // 2)
        return 2 * a - 1
    else:
        a = winner(x // 2)
        return 2 * a + 1


def main():
    inp = 3017957
    print(winner(inp))
    

main()
