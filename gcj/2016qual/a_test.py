def multiples(x):
    i = 1
    while True:
        yield i * x
        i += 1

for i in range(1000000):
    count = 45
    si = str(i)
    if si in ["125", "1250", "12500", "125000", "1250000"]:
        print("PLAH!", i)
        count = 100

    seen = [False] * 10
    for j in multiples(i):
        if count == 0:
            break

        for c in str(j):
            seen[int(c)] = True 

        count -= 1
        if (all(seen)):
            break
    
    for x in seen:
        if not x:
            print("Did not compute", i)
            break
