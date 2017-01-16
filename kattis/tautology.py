import itertools

class WFF(object):
    def __init__(self, var=None, left=None, right=None):
        self.left = left
        self.right = right
        self.var = var

    def __repr__(self):
        return '{}({})({})'.format(self.var, self.left, self.right)

    def run(self, vars):
        if self.var == 'N':
            return not self.left.run(vars)
        elif self.var == 'K':
            return self.left.run(vars) and self.right.run(vars)
        elif self.var == 'A':
            return self.left.run(vars) or self.right.run(vars)
        elif self.var == 'C':
            return (not self.left.run(vars)) or self.right.run(vars)
        elif self.var == 'E':
            return self.left.run(vars) == self.right.run(vars)
        else:
            return vars[self.var]


def parse(s):
    head = s[0]
    if head in 'pqrst':
        return WFF(var=head), s[1:]
    elif head == 'N':
        left, remaining = parse(s[1:])
        return WFF(var=head, left=left), remaining
    else:
        left, remaining = parse(s[1:])
        right, remaining = parse(remaining)
        return WFF(var=head, left=left, right=right), remaining


def main():
    s = input()
    while s != '0':
        tree, _ = parse(s)

        var_names = 'pqrst'
        result = True

        for combo in itertools.product([True, False], repeat=5):
            vars = dict(zip(var_names, combo))
            result = result and tree.run(vars)

        print('tautology' if result else 'not')

        s = input()


main()
