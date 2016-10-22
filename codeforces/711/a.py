n = int(input())
bus = []
works = False

for _ in range(n):
    bus.append(input())

for i, row in enumerate(bus):
    if row[:2] == "OO":
        bus[i] = "++" + row[2:]
        works = True
        break
    elif row[-2:] == "OO":
        bus[i] = row[:-2] + "++"
        works = True
        break

if works:
    print("YES")
    print('\n'.join(bus))
else:
    print("NO")
