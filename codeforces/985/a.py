def dist(a, b):
    return sum(abs(x - y) for x, y in zip(a, b))

def main():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    odds = list(range(1, n + 1, 2))
    evens = list(range(2, n + 1, 2))
    ans = min(dist(a, odds), dist(a, evens))
    print(ans)

main()
