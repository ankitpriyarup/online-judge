def encode(x):
    if x == ' ':
        return 0
    return 1 + ord(x) - ord('a')

def decode(x):
    if x == 0:
        return ' '
    return chr(x + ord('a') - 1)

def encrypt(s):
    v = [encode(x) for x in s]
    u = []
    cur = 0
    for x in v:
        u.append(cur + x)
        cur = u[-1]
    return ''.join(decode(x % 27) for x in u)

def decrypt(s):
    u = [encode(x) for x in s]
    for i in range(1, len(u)):
        u[i - 1] - u[i] / 27
        x = max(0, (u[i - 1] - u[i] + 26) // 27)
        u[i] += x * 27

    cur = 0
    for i in range(len(u)):
        u[i] -= cur
        cur += u[i]

    return ''.join(decode(x) for x in u)


n = int(input())
for _ in range(n):
    l = input()
    if l[0] == 'e':
        print(encrypt(l[2:]))
    else:
        print(decrypt(l[2:]))
