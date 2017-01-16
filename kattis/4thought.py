from collections import defaultdict
import itertools

def main():
    ALL_OPS = [' + ', ' - ', ' * ', ' // ']
    lookup = defaultdict(int)

    for ops in itertools.product(ALL_OPS, repeat=3):
        command = '4' + '4'.join(ops) + '4'
        result = eval(command)

        lookup[result] = command.replace('//', '/')

    cases = int(input())
    for _ in range(cases):
        v = int(input())
        if v in lookup:
            print(lookup[v], '=', v)
        else:
            print('no solution')

main()
