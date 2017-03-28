
# b + x * a = d + y * c
# x * a - y * c = d - b

def main():
    a, b = map(int, input().split())
    c, d = map(int, input().split())

    s1 = set([b + t * a for t in range(200)])
    s2 = set([d + t * c for t in range(200)])

    ans = float('inf')
    for x in s1:
        if x in s2:
            ans = min(ans, x)

    if ans == float('inf'):
        print(-1)
    else:
        print(ans)

main()
