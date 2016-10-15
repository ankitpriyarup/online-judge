def main():
    n = int(input())

    prereqs = {}
    for _ in range(n):
        line = input().split()
        name = line[0]
        prereq = line[2:]
        prereqs[name] = frozenset(prereq)

    order = input().split()
    safe = True
    used = set()

    for chem in order:
        if chem in prereqs:
            for preq in prereqs[chem]:
                if preq not in used:
                    safe = False
                    break

        used.add(chem)


    print("SAFE!" if safe else "BOOM!")

main()
