from collections import defaultdict

def classify(domain, codomain, mappings):
    f = {}
    rev = defaultdict(list)

    for a, b in mappings:
        if a in f:
            return 'not a function'
        f[a] = b
        rev[b].append(a)

    injective = all(len(v) == 1 for _, v in rev.items())
    surjective = codomain == set(v for _, v in f.items())
    if injective and surjective:
        return 'bijective'
    elif injective:
        return 'injective'
    elif surjective:
        return 'surjective'
    else:
        return 'neither injective nor surjective'

while True:
    try:
        domain = list(input().split())
        codomain = list(input().split())
    except:
        break

    domain = set(domain[1:])
    codomain = set(codomain[1:])
    n = int(input())
    mappings = []
    for _ in range(n):
        a, _, b = input().split()
        mappings.append((a, b))
    print(classify(domain, codomain, mappings))

