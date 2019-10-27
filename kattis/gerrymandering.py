#!/usr/bin/env python3

def main():
    p, m = map(int, input().split())
    votes = [[0, 0] for _ in range(m)]
    total_votes = 0
    for _ in range(p):
        d, a, b = map(int, input().split())
        d -= 1
        votes[d][0] += a
        votes[d][1] += b
        total_votes += a + b

    wasted = [0, 0]
    for i in range(m):
        precint_votes = sum(votes[i])
        needed = (precint_votes // 2) + 1

        if votes[i][0] > votes[i][1]:
            wasted[0] += votes[i][0] - needed
            wasted[1] += votes[i][1]
            print('A', votes[i][0] - needed, votes[i][1])
        else:
            wasted[0] += votes[i][0]
            wasted[1] += votes[i][1] - needed
            print('B', votes[i][0], votes[i][1] - needed)

    gap = abs(wasted[0] - wasted[1]) / total_votes
    print('{:.9f}'.format(gap))

if __name__ == '__main__':
    main()
