from collections import defaultdict
import sys

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71]

results = defaultdict(lambda: float('inf'))
seen = set()

facts = [1, 1, 2]
CAP = 1 << 63

def get_facts():
    for i in range(3, 64):
        facts.append(facts[-1] * i)

def compute(d):
    ans = facts[sum(d)]
    for x in d:
        ans //= facts[x]

    return ans

def search(distribution, value):
    if distribution in seen:
        return

    # print(distribution, value)
    seen.add(distribution)

    size = len(distribution)
    copy = list(distribution)

    score = compute(distribution)
    results[score] = min(results[score], value)

    for i in range(size):
        if i == 0 or distribution[i] < distribution[i - 1]:
            new_value = value * primes[i]

            if new_value <= CAP:
                copy[i] += 1
                search(tuple(copy), new_value)
                copy[i] -= 1

    if size < len(primes):
        copy = list(distribution) + [1]
        new_value = value * primes[size]
        if new_value <= CAP:
            search(tuple(copy), new_value)

def main():
    get_facts()

    distro = (1,)
    search(distro, 2)

    for line in sys.stdin.readlines():
        n = int(line.strip())
        print(n, results[n])

main()
