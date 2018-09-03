s, p = map(int, input().split())
if p <= s:
    print(0)
elif p < s + 60 * 5:
    print(1)
elif p < s + 60 * 15:
    print(2)
elif p < s + 60 * 30:
    print(3)
else:
    print(4)
