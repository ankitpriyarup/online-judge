N = int(raw_input())

ans1 = []
for i in xrange(N - 1, 0, -2):
    ans1.append(i)

for i in xrange(N, 0, -2):
    if len(ans1) > 0 and abs(ans1[-1] - i) == 1:
        break

    ans1.append(i)

ans2 = []
for i in xrange(N, 0, -2):

    ans2.append(i)

for i in xrange(N - 1, 0, -2):
    if len(ans2) > 0 and abs(ans2[-1] - i) == 1:
        break
    ans2.append(i)

if len(ans1) > len(ans2):
    ans = ans1
else:
    ans = ans2

print len(ans)
print ' '.join(map(str, ans))
