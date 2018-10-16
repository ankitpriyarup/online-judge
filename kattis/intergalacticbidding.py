n, s = map(int, input().split())
parts = []
for _ in range(n):
    a, b = input().split()
    parts.append((int(b), a))
parts.sort(reverse=True)
winners = []
for b, a in parts:
    if b <= s:
        s -= b
        winners.append(a)

if s == 0:
    print(len(winners))
    for winner in winners:
        print(winner)
else:
    print(0)
