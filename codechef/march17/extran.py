from collections import Counter

def main():
    T = int(input())
    for _ in range(T):
        n = int(input())
        c = Counter(map(int, input().split()))

        ans = -1
        for x in c:
            if c[x] > 1 or ((x - 1) not in c and (x + 1) not in c):
                ans = x
                break

        print(ans)

main()
