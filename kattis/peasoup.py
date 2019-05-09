T = int(input())
ans = None
for _ in range(T):
    k = int(input())
    name = input()
    foods = set(input() for _ in range(k))
    if 'pea soup' in foods and 'pancakes' in foods:
        ans = name
        break

if ans is None:
    print('Anywhere is fine I guess')
else:
    print(ans)
