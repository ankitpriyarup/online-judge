def clean(s):
    return ''.join([x for x in s.lower() if (x not in ";-_")])

a = clean(input())
b = clean(input())
c = clean(input())

opts = [a + b + c, a + c + b, b + a + c, b + c + a, c + a + b, c + b + a]
T = int(input())
for _ in range(T):
    test = clean(input())
    print("ACC" if test in opts else "WA")

