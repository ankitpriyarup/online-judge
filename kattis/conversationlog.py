def main():
    n = int(input())
    d = {}
    users = {}
    uses = {}

    people = set()

    for _ in range(n):
        line = input().split()
        name = line[0]
        words = line[1:]
        d[name] = words

        people.add(name)

        for word in words:
            if word not in users:
                users[word] = set()

            users[word].add(name)

            if word not in uses:
                uses[word] = 0

            uses[word] += 1

    num_users = len(people)
    out = []
    for word in users:
        if len(users[word]) == num_users:
            out.append((uses[word], word))

    out.sort(key=lambda x: (-x[0], x[1]))

    for _, word in out:
        print(word)

    if out == []:
        print('ALL CLEAR')

main()
