P = int(input())
ans = [0]
for i in range(1, 10001):
    ans.append(ans[-1] + i + 1)
for _ in range(P):
    k, v = map(int, input().split())
    print(k, ans[v])
