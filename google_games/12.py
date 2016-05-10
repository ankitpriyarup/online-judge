meetings = []
for c in "ABCDEFGHIJKL":
    a, b = map(float, input().split())
    meetings.append((c, a, b))

meetings.sort(key=lambda x: x[2])
print(meetings)
