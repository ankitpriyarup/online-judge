n = int(raw_input())
a = map(int, raw_input().split())
evens = filter(lambda x: x % 2 == 0, a)
odds = filter(lambda x: x % 2 == 1, a)

ans = sum(evens)
odds.sort()

if len(odds) % 2 == 1:
    ans += sum(odds[1:])
else:
    ans += sum(odds)

print ans
