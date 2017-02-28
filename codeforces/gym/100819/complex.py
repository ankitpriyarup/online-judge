from collections import Counter

def main():
    s = input()
    c = Counter(s)

    ans = c.most_common()
    ans.sort(key=lambda x: x[1])

    o = 0
    for i in range(0, len(ans) - 2):
        o += ans[i][1]

    print(o)

main()
