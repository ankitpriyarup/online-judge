from collections import Counter

def main():
    n = int(input())
    words = [input().lower() for _ in range(n)]
    counter = Counter()

    for word in words:
        key = ''.join(sorted(list(word)))
        counter[key] += 1

    ans = 0
    for word in words:
        key = ''.join(sorted(list(word)))
        if counter[key] > 1:
            ans += 1

    print(ans)

main()
