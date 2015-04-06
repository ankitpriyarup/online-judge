PI = '31415926535897932384626433833'
T = int(raw_input())

for case_num in xrange(T):
    words = raw_input().split()
    works = True
    for index, word in enumerate(words):
        if len(word) != int(PI[index]):
            works = False
            break
    if works:
        print 'It\'s a pi song.'
    else:
        print 'It\'s not a pi song.'
