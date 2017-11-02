from collections import defaultdict

def main():
    n = int(input())
    a = list(input().split())
    pos = 0
    graph = defaultdict(list)
    for x in a:
        if len(x) > 1:
            dur = int(x[1:])
        else:
            dur = 1
        x = x[0]

        for _ in range(dur):
            graph[x].append(pos)
            pos += 1

        pos += 1

    has_lines = 'aegBDF'
    for note in 'GFEDCBAgfedcba':
        print(note + ': ', end='')
        sep = '-' if note in has_lines else ' '

        ptr = 0
        out = []
        last_beat = 0
        for beat in range(pos - 1):
            if ptr < len(graph[note]) and graph[note][ptr] == beat:
                out.append('*')
                last_beat = beat
                ptr += 1
            else:
                out.append(sep)

        print(''.join(out))

main()
