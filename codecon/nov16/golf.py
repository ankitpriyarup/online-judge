import itertools

def main():
    n = int(input())
    clubs = list(map(int, input().split()))
    m = int(input())
    holes = list(map(int, input().split()))

    q = clubs[:]
    options = set()
    while q:
        top = q[0]
        q = q[1:]
        if top in options:
            continue

        options.add(top)

        for club in clubs:
            if -700 < top + club < 700:
                q.append(top + club)

            if -700 < top - club < 700:
                q.append(top - club)

    for hole in holes:
        print("yes" if hole in options else "no")

main()
