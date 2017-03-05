from itertools import permutations

suit_map = 'shdc'
rank_map = '23456789TJQKA'

def to_num(card):
    suit = suit_map.index(card[1])
    rank = rank_map.index(card[0])

    return 13 * suit + rank

def generate(perm, flips):
    flip_bit = 1
    out = []
    for i in range(4):
        start = perm[i] * 13
        cur = list(range(start, start + 13))
        if flips & (1 << i):
            cur.reverse()

        out += cur

    return out

def lis(a, b):
    n = len(a)
    m = len(b)
    prev = [0] * (n + 1)

    for j in range(1, m + 1):
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            if a[i - 1] == b[j - 1]:
                dp[i] = 1 + prev[i - 1]

            dp[i] = max(dp[i], dp[i - 1])
            dp[i] = max(dp[i], prev[i])

        prev = dp

    return prev[-1]

def main():
    n = int(input())
    hand = list(map(to_num, input().split()))

    ans = n - 1

    for suit_perm in permutations(range(4)):
        if ans == 0:
            break

        for orders in range(16):
            target = generate(suit_perm, orders)
            ans = min(ans, n - lis(hand, target))

            if ans == 0:
                break

    print(ans)

main()
