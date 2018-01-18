def main():
    n, k = map(int, input().split())
    history = [0]
    moves = list(input().split())

    undo = False
    for move in moves:
        if move == 'undo':
            undo = True
        elif undo:
            undo = False
            x = int(move)
            for _ in range(x):
                history.pop()
        else:
            x = int(move)
            history.append((history[-1] + 3 * n + x) % n)

    print(history[-1])

main()
