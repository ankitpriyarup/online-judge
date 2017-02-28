leet = {'A': '@',
'B': '8',
'C': '(',
'D': '|)',
'E': '3',
'F': '#',
'G': '6',
'H': '[-]',
'I': '|',
'J': '_|',
'K': '|<',
'L': '1',
'M': r'[]\/[]',
'N': r'[]\[]',
'O': '0',
'P': '|D',
'Q': '(,)',
'R': '|Z',
'S': '$',
'T': r"']['",
'U': '|_|',
'V': r'\/',
'W': r'\/\/',
'X': '}{',
'Y': r'`/',
'Z': '2' }


def convert(c):
    if 'a' <= c <= 'z':
        return leet[chr(ord(c) - ord('a') + ord('A'))]
    elif 'A' <= c <= 'Z':
        return leet[c]
    else:
        return c

s = input()
print(''.join(convert(c) for c in s))
