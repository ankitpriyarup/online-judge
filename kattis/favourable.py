def dfs(graph, memo, good, node):
    if node in good:
        return 1
    if node not in graph:
        return 0
    if node in memo:
        return memo[node]

    ans = 0
    for child in graph[node]:
        ans += dfs(graph, memo, good, child)

    memo[node] = ans
    return ans

def main():
    num_sections = int(input())
    good = set()
    graph = {}

    for _ in range(num_sections):
        data = input().split()
        page_number = int(data[0])

        if len(data) == 4:
            options = tuple(map(int, data[1:]))
            graph[page_number] = options
        else:
            assert(len(data) == 2)
            outcome = data[1]
            if outcome[0] == 'f':
                good.add(page_number)

    memo = {}
    print(dfs(graph, memo, good, 1))

T = int(input())
for _ in range(T):
    main()
