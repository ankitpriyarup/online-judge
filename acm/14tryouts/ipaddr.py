def tobin(ar):
    return (ar[0] << 24) | (ar[1] << 16) | (ar[2] << 8) | ar[3]

def tostr(ans):
    return ".".join(map(str, [int(ans[0:8], 2), int(ans[8:16], 2), int(ans[16:24], 2), int(ans[24:32], 2)]))

T = int(raw_input())
for ttt in xrange(T):
    N = int(raw_input())
    addrs = []
    for i in xrange(N):
        addrs.append(map(int, raw_input().split('.')))
    paddrs = [tobin(ip) for ip in addrs]
    a = min(paddrs)
    b = max(paddrs)
    if a == b:
        print '.'.join(map(str, addrs[0])) + '/32'
    else:
        bit = (1 << 32)
        ans = ""
        while ((a & bit) == (b & bit)):
            bit >>= 1
            ans += ('0' if str(a & bit)  == '0' else '1')
        l = len(ans) - 1
        ans += '0'*(32 - l)
        reall = 0
        ind = -1
        while((ind*-1 <= l + 1) and ans[ind] == '0'):
            reall += 1
            ind -= 1
        print tostr(ans) + '/' + str(l)

