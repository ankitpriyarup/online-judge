def main():
    d, g = map(int, input().split())
    probs = []
    ans = 0
    for i in range(d):
        p, c = map(int, input().split())
        probs.append(((i + 1) * 100, p, c))
        ans += p

    for mask in range(1 << d):
        solved = 0
        my_score = 0
        for i in range(d):
            score, occ, bonus = probs[i]
            if (mask & (1 << i)) > 0:
                solved += occ
                my_score += score * occ + bonus

        for x in range(d - 1, -1, -1):
            if my_score >= g:
                break
            if (mask & (1 << x)) > 0:
                continue
            score, occ, bonus = probs[x]
            for _ in range(occ):
                solved += 1
                my_score += score
                if my_score >= g:
                    break
        if my_score >= g:
            ans = min(ans, solved)

    print(ans)

main()
