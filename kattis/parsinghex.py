import sys

for line in sys.stdin:
    s = line.strip()
    n = len(s)
    i = 0
    while i + 2 <= n:
        if s[i:i + 2] in ['0x', '0X']:
            j = i + 2
            while j < n and s[j] in '0123456789abcdefABCDEF':
                j += 1

            chunk = s[i:j]
            if j != i + 2:
                print(chunk, int(chunk[2:], 16))
            i = j
        else:
            i += 1
