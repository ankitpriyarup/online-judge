from collections import defaultdict, deque

def main():
    graph = defaultdict(list)
    n = int(input())
    for _ in range(n):
        line = input().split()
        station = line[0]
        conns = line[1:]

        graph[station] = conns
        for c in conns:
            graph[c].append(station)

    start, end = input().split()
    q = deque([start])
    prev = {start: ''}
    while q:
        cur = q.popleft()
        for dst in graph[cur]:
            if dst not in prev:
                prev[dst] = cur
                q.append(dst)

    if end not in prev:
        print('no route found')
        return

    cur = end
    out = []
    while cur != start:
        out.append(cur)
        cur = prev[cur]

    out.append(start)
    out.reverse()

    print(' '.join(out))

main()
