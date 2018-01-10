import sys

def main():
    lines = [line.strip() for line in sys.stdin]
    w = max(len(l) for l in lines) + 2
    print('*' * w)
    flag = True
    for line in lines:
        extra = w - 2 - len(line)
        if extra % 2 != 0:
            if flag:
                left = extra  // 2
                right = extra - left
            else:
                right = extra // 2
                left = extra - right

            flag = not flag
        else:
            left = extra // 2
            right = extra // 2

        print('*' + ' ' * left + line + ' ' * right + '*')
    print('*' * w)

main()
