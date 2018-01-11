def shift(s, amt):
    return s[amt:] + s[:amt]

def main():
    s = input()
    q = int(input())
    for _ in range(q):
        l, r, k = map(int, input().split())
        l -= 1
        k %= (r - l)
        s = s[:l] + shift(s[l:r], r - l - k) + s[r:]

    print(s)


main()
