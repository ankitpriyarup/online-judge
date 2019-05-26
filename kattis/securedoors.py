n = int(input())
here = set()
for _ in range(n):
    op, name = input().split()
    if op == 'entry':
        anom = name in here
        here.add(name)
        print(name, 'entered', '(ANOMALY)' if anom else '')
    else:
        anom = name not in here
        if not anom:
            here.remove(name)
        print(name, 'exited', '(ANOMALY)' if anom else '')

