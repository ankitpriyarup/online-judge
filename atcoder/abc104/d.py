def main():
    s = input()
    pa = [0]
    pb = [0]
    pc = [0]
    pd = [0]

    n = len(s)
    for i in range(n):
        pa.append(pa[-1])
        pb.append(pb[-1])
        pc.append(pc[-1])
        pd.append(pd[-1])

        if s[i] == 'A':
            pa[-1] += 1
        elif s[i] == 'B':
            pb[-1] += 1
        elif s[i] == 'C':
            pc[-1] += 1
        elif s[i] == '?':
            pd[-1] += 1

    totq = pd[n]

    MOD = 1000000007
    ans = 0
    for i in range(1, n + 1):
        if s[i - 1] == 'A' or s[i - 1] == 'C':
            continue

        if s[i - 1] == 'B':
            buf = 0
        else:
            buf = 1

        # ABC ?BC AB? ?B?
        a_bef = pa[i - 1]
        d_bef = pd[i - 1]
        c_aft = pc[n] - pc[i]
        d_aft = pd[n] - pd[i]

        if a_bef * c_aft > 0:
            ans += (a_bef * c_aft % MOD) * pow(3, totq - buf, MOD) % MOD
            ans %= MOD

        if d_bef * c_aft > 0:
            ans += (d_bef * c_aft % MOD) * pow(3, totq - buf - 1, MOD) % MOD
            ans %= MOD

        if a_bef * d_aft > 0:
            ans += (a_bef * d_aft % MOD) * pow(3, totq - buf - 1, MOD) % MOD
            ans %= MOD
        
        if d_bef * d_aft > 0:
            ans += (d_bef * d_aft % MOD) * pow(3, totq - buf - 2, MOD) % MOD
            ans %= MOD

    print(ans)

main()
