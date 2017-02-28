import re

def rc(s):
    valid = re.compile(r'R(\d+)C(\d+)')
    match = valid.match(s)
    if match is None:
        return None, None
    else:
        return list(map(int, match.groups()))

def excel_to_int(s):
    ans = 0
    for c in s:
        ans += ord(c) - ord('A')
        ans += 1
        ans *= 26

    return ans // 26

def int_to_excel(x):
    out = []
    while x:
        x -= 1
        out.append(chr(ord('A') + int(x % 26)))
        x //= 26

    return ''.join(reversed(out))

def main():
    n = int(input())
    for _ in range(n):
        s = input()
        x, y = rc(s)

        if x is None:
            row_start = 0
            while s[row_start] not in '0123456789':
                row_start += 1

            col_excel = s[:row_start]
            col = excel_to_int(col_excel)
            row = s[row_start:]

            print('R{}C{}'.format(row, col))
        else:
            col = int_to_excel(y)
            print('{}{}'.format(col, x))

main()
