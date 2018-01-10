from collections import Counter

def main():
    n = int(input())
    s = input()
    c = Counter(s)
    ans = min(c['L'], c['R']) + min(c['U'], c['D'])

    print(2 *ans)

main()
