import sys

def main():
    lens = []
    for line in sys.stdin:
        n = len(line.strip())
        lens.append(n)

    x = max(lens)
    ans = 0
    for c in lens[:-1]:
        ans += (x - c) * (x - c)

    print(ans)

main()
