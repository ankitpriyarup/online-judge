def main():
    n = int(input())
    s = input()
    t = input()
    a = ''.join(sorted(s))
    b = ''.join(sorted(t))
    if a != b:
        print(-1)
        return

    k = 0
    moves = []
    for i in range(n):
        while s[i] != t[i]:
            p = -1
            for j in range(i + 1, n):
                if s[j] == t[i]:
                    p = j
                    break

            assert p != -1
            for x in range(j - 1, i - 1, -1):
                moves.append(str(x + 1))
            k += j - i
            s = s[:i] + s[j] + s[i:j] + s[j + 1:]
    assert len(moves) == k
    print(k)
    print(' '.join(moves))

main()
