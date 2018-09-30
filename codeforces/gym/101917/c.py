def convert(c, s):
    if ord('A') <= ord(c) <= ord('Z'):
        return chr(((ord(c) - ord('A') - s + 26) % 26) + ord('A'))
    elif ord('a') <= ord(c) <= ord('z'):
        return chr(((ord(c) - ord('a') - s + 26) % 26) + ord('a'))
    else:
        return c

n, shift = map(int, input().split())
shift %= 26
for _ in range(n):
    s = input()
    s = ''.join(convert(c, shift) for c in s)
    print(s)

