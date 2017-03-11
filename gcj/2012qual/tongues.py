inp = ["ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"]
out = ["our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"]

table = {'y': 'a', 'e': 'o', 'q': 'z', 'z': 'q'}

for i in range(3):
    for j in range(len(inp[i])):
        table[inp[i][j]] = out[i][j]

n = int(input())
for i in range(n):
    decode = ''.join(table[c] for c in input())
    print("Case #{}: {}".format(i + 1, decode))
