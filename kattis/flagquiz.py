def diff(a, b):
    assert(len(a) == len(b))
    score = 0
    for i, e in enumerate(a):
        if e != b[i]:
            score += 1

    return score

def main():
    input()
    n = int(input())
    commands = []
    for _ in range(n):
        command = input()
        commands.append(command.split(', '))

    scores = [0] * n

    for i, command in enumerate(commands):
        for other in commands:
            if other != command:
                scores[i] = max(scores[i], diff(command, other))

    best = min(scores)
    for i, command in enumerate(commands):
        if scores[i] == best:
            print(', '.join(command))


main()
