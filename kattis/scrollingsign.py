def main():
    k, w = map(int, input().split())
    words = [input().strip() for _ in range(w)]
    ans = k * w
    for i in range(1, w):
        overlap = 0
        for j in range(k, -1, -1):
            if words[i - 1][k - j:] == words[i][:j]:
                overlap = j
                break

        ans -= overlap
    print(ans)

T = int(input())
for _ in range(T):
    main()
