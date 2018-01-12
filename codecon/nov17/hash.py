from collections import defaultdict, deque, Counter
import itertools
import math
import sys

def main():
    n = int(input())
    links = defaultdict(list)
    for _ in range(n):
        node, hash_id = input().split()
        links[node].append(hash_id)

    by_ends = defaultdict(list)
    for node in links:
        by_ends[(links[node][0], links[node][-1])].append(tuple(links[node]))

    safe = defaultdict(list)
    for ends in by_ends:
        all_links = by_ends[ends]
        freq = [Counter() for _ in range(max(len(link) for link in all_links))]
        for link in all_links:
            for i in range(1, len(link) - 1):
                freq[i][link[i]] += 1

        agreements = 0
        for link in all_links:
            agree = True
            for i in range(1, len(link) - 1):
                expected = freq[i].most_common()[0][0]
                if link[i] != expected:
                    agree = False

            if agree:
                safe[ends].append(link)

    best_for_ends = {}
    for ends in safe:
        best_for_ends[ends] = max(safe[ends], key=lambda x: len(x))

    best_end = max(safe.keys(), key=lambda end: (len(safe[end]), len(best_for_ends[end])))
    print(' '.join(best_for_ends[best_end]))

main()
