from collections import Counter

n = int(input())
a = map(int, input().split())
freq = Counter(a)
best_count = freq.most_common()[0][1]

for i in range(1, 6):
    if freq[i] == best_count:
        print(i)
        break        
