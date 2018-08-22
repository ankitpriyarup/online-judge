n, b = input().split()
n = int(n)
dom = {'A': 11, 'K': 4, 'Q': 3, 'J': 20, 'T': 10, '9': 14, '8': 0, '7': 0}
non = {'A': 11, 'K': 4, 'Q': 3, 'J': 2, 'T': 10, '9': 0, '8': 0, '7': 0}
ans = 0

for _ in range(4 * n):
    hand = input()
    num, suit = list(hand)
    if suit == b:
        ans += dom[num]
    else:
        ans += non[num]

print(ans)
