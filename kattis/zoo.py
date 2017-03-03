from collections import Counter

def main():
    case = 1
    while True:
        n = int(input())
        if n == 0:
            break

        names = set()
        count = Counter()
        for _ in range(n):
            name = input().split()
            name = name[-1].lower()
            names.add(name)
            count[name] += 1

        print('List {}:'.format(case))
        names = list(names)
        names.sort()

        for name in names:
            print('{} | {}'.format(name, count[name]))

        case += 1

main()
