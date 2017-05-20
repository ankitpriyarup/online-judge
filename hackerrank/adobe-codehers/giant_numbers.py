from collections import Counter

MAXN = 100005

def main():
    n = int(input())
    a = Counter(map(int, input().split()))
    ans = [0] * MAXN
    for v in a:
        val = v
        while val < MAXN:
            ans[val] += a[v]
            val += v

    q = int(input())
    for _ in range(q):
        x, k = map(int, input().split())
        print("Yes" if ans[x] >= k else "No")
        
main()
