T = int(raw_input())
for ll in xrange(T):
    s = set()
    r = int(raw_input()) - 1

    board = []
    for i in range(4):
        board.append([])
        board[i] = map(int, raw_input().split())
    s.update(board[r])
    c = int(raw_input()) - 1

    board = []
    for i in range(4):
        board.append([])
        board[i] = map(int, raw_input().split())

    s = s.intersection(board[c])

    out = ''
    if len(s) == 1:
        out = str(list(s)[0])
    elif len(s) == 0:
        out = 'Volunteer cheated!'
    else:
        out = 'Bad magician!'
    print 'Case #%d: %s' % (ll+1, out)
