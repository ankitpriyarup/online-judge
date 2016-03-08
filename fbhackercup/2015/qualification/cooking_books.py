T = int(raw_input())
for case in xrange(1, T + 1):
    word = raw_input()
    lenword = len(word)
    smallest = int(word)
    largest = int(word)

    for i in xrange(0, lenword):
        for j in xrange(i + 1, lenword):
            flip = word[0:i] + word[j] + word[(i + 1):j] + word[i] + word[(j+1):]
            iflip = int(flip)

            if iflip < smallest and flip[0] != '0':
                smallest = iflip

            if iflip > largest:
                largest = iflip

    print "Case #" + str(case) + ":", smallest, largest
