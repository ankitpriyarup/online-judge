from functools import lru_cache

@lru_cache(maxsize=None)
def solve(a, b, c):
    ans = 0
    for x in range(a + 1, b):
        ans = max(ans, 1 + solve(a, x, b))
    for x in range(b + 1, c):
        ans = max(ans, 1 + solve(b, x, c))

    return ans

a, b, c = map(int, input().split())
print(solve(a, b, c))
