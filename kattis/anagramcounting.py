from collections import Counter
import sys

fact = [1]
for i in range(1, 101):
    fact.append(i * fact[-1])

def main():
    for line in sys.stdin.readlines():
        line = line.strip()
        n = len(line)
        c = Counter(line)

        ans = fact[n]
        for x in c:
            ans //= fact[c[x]]

        print(ans)

main()
