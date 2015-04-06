T = int(raw_input())
for case_num in xrange(T):
    K = int(raw_input())
    s = raw_input()
    alphabet = raw_input()

    letters = set(s)
    if '_' in letters:
        letters.remove('_')

    n = len(letters)
    wrong = 0
    for i, letter in enumerate(alphabet):
        if n == 0:
            break
        if letter in letters:
            letters.remove(letter)
            n -= 1
        else:
            wrong += 1 

    print "Are they psychic?!" if wrong == 0 else wrong
