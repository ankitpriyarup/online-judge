def main():
    m, k = map(int, input().split())
    ans = list(map(int, input().split()))[1:]
    for _ in range(1, m):
        current = list(map(int, input().split()))[1:]
        next_ans = [x + y for x in ans for y in current]
        next_ans.sort()
        ans = next_ans[:k]

    print(' '.join(str(x) for x in ans))


T = int(input())
for _ in range(T):
    main()
