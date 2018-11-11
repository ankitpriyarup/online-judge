from __future__ import print_function

# Seems to only work with pypy, not cpython
def main():
    a = raw_input()
    b = raw_input()
    n = len(a)
    ans = 'NONE'

    for k in range(n, 0, -1):
        s = set()
        state = [0] * 26

        for i in range(k):
            state[ord(b[i]) - ord('a')] += 1

        s.add(tuple(state))
        for i in range(k, n):
            state[ord(b[i]) - ord('a')] += 1
            state[ord(b[i - k]) - ord('a')] -= 1
            s.add(tuple(state))

        state = [0] * 26
        for i in range(k):
            state[ord(a[i]) - ord('a')] += 1

        if tuple(state) in s:
            print(a[:k])
            return

        for i in range(k, n):
            state[ord(a[i]) - ord('a')] += 1
            state[ord(a[i - k]) - ord('a')] -= 1
            if tuple(state) in s:
                print(a[i - k + 1:i + 1])
                return
    print('NONE')

T = int(raw_input())
for _ in range(T):
    main()
