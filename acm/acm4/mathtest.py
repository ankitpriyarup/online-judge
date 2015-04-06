T = int(raw_input())
for case_num in xrange(T):
    N = int(raw_input())
    correct = 0
    for i in xrange(N):
        tokens = raw_input().split()
        a = tokens[0]
        op = tokens[1]
        b = tokens[2]
        ans = tokens[4]

        if op == '+' and int(a) + int(b) == int(ans):
            correct += 1
        elif op == '-' and int(a) - int(b) == int(ans):
            correct += 1
        elif op == '*' and int(a) * int(b) == int(ans):
            correct += 1
    print str(int(round(100.0 * correct / N))) + '%'

