def main():
    s = input()
    last = s[0]
    safe = True
    zone = {'C': 0, 'E': 1, 'S': 2}
    for c in s:
        safe = safe and zone[c] >= zone[last]
        last = c

    print('yes' if safe else 'no')

t = int(input())
for _ in range(t):
    main()
