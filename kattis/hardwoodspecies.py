from collections import Counter
import sys

freq = Counter(line.strip() for line in sys.stdin)
freq = freq.most_common()
freq.sort()
total = sum(f[1] for f in freq)
for name, occ in freq:
    print(name, 100.0 * occ / total)
