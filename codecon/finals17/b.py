from collections import Counter

cards = 'JQKA'
suits = 'hdsc'

points = {'J': 11, 'Q': 12, 'K': 13, 'A': 14}

def _score(hand):
    suitfreq = Counter()
    cardfreq = Counter()

    for c in hand:
        cardfreq[c[0]] += 1
        suitfreq[c[1]] += 1

    score = 0
    for c in hand:
        score += points[c[0]] * cardfreq[c[0]]

    score *= suitfreq.most_common()[0][1]

    return score


def score(hand):
    if 'Joker' in hand:
        i = hand.index('Joker')
        ans = 0
        for c in cards:
            for s in suits:
                ans = max(ans, _score(hand[:i] + [c + s] + hand[i + 1:]))

        return ans
    else:
        return _score(hand)



def main():
    n = int(input())

    inp = input().split()
    hands = [list() for _ in range(n)]
    for x in range(n * 5):
        hands[x % n].append(inp[x])

    scores = list(map(score, hands))

    best = max(scores)
    winners = []
    for i in range(n):
        if scores[i] == best:
            winners.append(i)

    if len(winners) > 1:
        print('tie', best)
    else:
        print(winners[0] + 1, best)

main()
