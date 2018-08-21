def match(a, b):
    return sum(1 for i in range(len(b)) if a[i % len(a)] == b[i])

seqs = ['ABC', 'BABC', 'CCAABB']
names = ['Adrian', 'Bruno', 'Goran']
n = int(input())
s = input()
scores = [match(seq, s) for seq in seqs]
m = max(scores)
print(m)
for i in range(3):
    if scores[i] == m:
        print(names[i])
