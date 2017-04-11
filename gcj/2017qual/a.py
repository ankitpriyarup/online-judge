def solve():
    s, k = input().split()
    s = [x == '+' for x in s]
    k = int(k)

    flips = 0
    for i in range(len(s) - k + 1):
        if not s[i]:
            flips += 1
            for j in range(i, i + k):
                s[j] = not s[j]

    if any(x is False for x in s):
        return 'IMPOSSIBLE'
    else:
        return flips

def main():
    t = int(input())
    for tt in range(t):
        print('Case #{}: {}'.format(tt + 1, solve()))

main()
