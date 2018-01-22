from collections import Counter

def main():
    f = Counter()
    while True:
        name = input()
        if name == '***':
            break
        f[name] += 1

    by_vote = f.most_common()

    ans = by_vote[0][0]
    count = by_vote[0][1]
    unique = 1 == sum(1 for k, v in by_vote if v == count)

    if unique:
        print(ans)
    else:
        print('Runoff!')

main()
