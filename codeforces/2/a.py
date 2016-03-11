from collections import defaultdict

def main():
    n = int(input())
    commands = []

    d = defaultdict(int)

    for _ in range(n):
        name, score = input().split()
        score = int(score)

        commands.append((name, score))
        d[name] += score

    best_score = 0
    for k, v in d.items():
        best_score = max(best_score, v)

    options = set()
    for k, v in d.items():
        if v == best_score:
            options.add(k)

    if len(options) == 1:
        print(list(options)[0])
    else:
        d = defaultdict(int)
        ans = ''
        for name, score in commands:
            d[name] += score

            if name in options and d[name] >= best_score:
                ans = name
                break

        print(ans)

main()
