from collections import *

def main():
    n = int(input())
    s = input()
    seen = set()

    ans = 0
    for i in range(n):
        if s[i].isupper():
            ans = max(ans, len(seen))
            seen = set()
        else:
            seen.add(s[i])

    ans = max(ans, len(seen))
    print(ans)

main()
