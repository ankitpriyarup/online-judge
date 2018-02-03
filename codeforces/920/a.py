def main():
    n, k = map(int, input().split())
    res = [float('inf') for _ in range(n)]
    sprinklers = list(map(lambda x: int(x) - 1, input().split()))
    for i in range(n):
        for j in sprinklers:
            res[i] = min(res[i], abs(j - i))

    print(1 + max(res))
    
T = int(input())
for _ in range(T):
    main()
