n = int(input())
spheres = []
for i in range(n):
    a, b, c = map(int, input().split())
    l = [a, b, c]
    l.sort(reverse=True)
    spheres.append((tuple(l), i + 1))

spheres.sort(reverse=True, key=lambda x: x[0])

ans = min(spheres[0][0])
k = 1
ind = [spheres[0][1]]

for i in range(1, n):
    if min(spheres[i][0]) > ans:
        ans = min(spheres[i][0])
        k = 1
        ind = [spheres[i][1]]

    me = spheres[i][0]
    last = spheres[i - 1][0]
    if me[0] == last[0] and me[1] == last[1]:
        rad = min(me[i] for i in range(2))
        rad = min(me[2] + last[2], rad)

        if rad > ans:
            ans = rad
            k = 2
            ind = [spheres[i - 1][1], spheres[i][1]]

print(k)
if k == 1:
    print(ind[0])
else:
    print(ind[0], ind[1])
