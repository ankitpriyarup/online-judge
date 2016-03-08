n, k = map(int, raw_input().split())
s = raw_input()

ans = []
for c in s:
    if k == 0:
        ans.append(c)
        continue

    a_dist = ord(c) - ord('a')
    z_dist = 25 - a_dist

    #print a_dist, z_dist
    if a_dist <= k and z_dist <= k:
        if a_dist > z_dist:
            ans.append('a')
            k -= a_dist
        else:
            ans.append('z')
            k -= z_dist
    else:
        c2 = ord(c) + k
        if c2 <= ord('z'):
            ans.append(chr(c2))
        else:
            ans.append(chr(ord(c) - k))
        k = 0

if k == 0:
    print ''.join(ans)
else:
    print -1
