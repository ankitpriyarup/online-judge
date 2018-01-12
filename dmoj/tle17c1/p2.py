def main():
    f = int(input())

    energies = {}
    for _ in range(f):
        s, e = input().split()
        e = int(e)
        energies[s] = e

    n = int(input())
    things = []
    for _ in range(n):
        food, loc = input().split()
        things.append((int(loc), food))

    energy = 0
    pos = 0
    eaten = 0

    things.sort()
    for loc, food in things:
        dist = loc - pos
        if dist != 0 and dist > energy:
            break

        energy -= dist
        pos = loc
        energy += energies[food]
        eaten += 1

    print(eaten)

main()
