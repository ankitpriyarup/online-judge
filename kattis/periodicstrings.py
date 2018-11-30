def periodic(n, s, k):
    prev = s[:k]
    for i in range(k, n, k):
        cur = s[i:i + k]
        if cur != prev[-1] + prev[:-1]:
            return False
        prev = cur
    return True

def main():
    s = input()
    n = len(s)
    for k in range(1, n + 1):
        if n % k != 0:
            continue

        if periodic(n, s, k):
            print(k)
            return

main()
