n = int(input())
m = {len(s): s for s in input().split()}
x = input()
for v in range(len(x), -1, -1):
    if v in m:
        print(m[v])
        break
