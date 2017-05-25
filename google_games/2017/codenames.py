from collections import deque, defaultdict

def run(graph, word, blue, bad):
    q = deque()
    q.append(word)

    seen = set([word])
    blue = set(blue)
    hit = 0

    while q:
        node = q.popleft()
        seen.add(node)

        if node in blue:
            hit += 1

        if node in bad:
            return False

        if hit == len(blue):
            return True

        for v in graph[node]:
            if v not in seen:
                seen.add(v)
                q.append(v)

    return False

def main():
    fin = open('codenames.txt', 'r')
    graph = defaultdict(list)
    for line in fin:
        line = line.strip()
        line = line.split(':')
        key = line[0]
        vals = line[1].split(',')

        for val in vals:
            graph[key].append(val)
            assert(len(graph[val]) >= 0)

    bad = ['pilot', 'zoo', 'battery', 'mortgage', 'water', 'egg', 'vacation', 'officer', 'judge', 'fate', 'truck', 'cross', 'kilometer', 'radio', 'cargo', 'diamond']
    blue = ['airplane', 'basket', 'plastic', 'spirit', 'meltdown', 'festival', 'quarter', 'pink', 'earth']

    for word in graph.keys():
        s = run(graph, word, blue, bad)
        if s:
            print(word)

main()
