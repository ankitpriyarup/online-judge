opts = list(range(1, 10))
n = int(input())
for k in range(2, n + 1):
    new_opts = set(10 * x + v for x in opts for v in range(10) if (10 * x + v) % k == 0)
    opts = new_opts
print(len(opts))
