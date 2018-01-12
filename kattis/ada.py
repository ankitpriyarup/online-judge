def done(v):
    for x in v:
        if x != v[0]:
            return False
    return True

def differences(v):
    n = len(v)
    out = []
    for i in range(1, n):
        out.append(v[i] - v[i - 1])

    return out

def main():
    vals = list(map(int, input().split()))
    degree = vals[0]
    v = vals[1:]

    ans = 1
    dd = differences(v)
    history = [v, differences(v)]
    while not done(history[-1]):
        history.append(differences(history[-1]))
        ans += 1

    l = len(history)
    for i in range(l - 2, -1, -1):
        history[i].append(history[i][-1] + history[i + 1][-1])

    print(ans, history[0][-1])

main()
