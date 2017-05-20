from functools import cmp_to_key
def solve():
    n = int(input())

    people = []
    for _ in range(n):
        name, rank, _ = input().split()
        name = name[:-1]
        rank = rank.split('-')
        people.append((rank, name))

    total_len = max(len(rank) for rank, _ in people)

    for i in range(len(people)):
        rank, name = people[i]
        people[i] = (tuple(reversed(['middle'] * (total_len - len(rank)) + rank)), name)

    people.sort(key=lambda x: x[1], reverse=True)
    people.sort(key=lambda x: x[0])

    for _, person in reversed(people):
        print(person)

def main():
    T = int(input())
    for _ in range(T):
        solve()
        print('=' * 30)

main()
