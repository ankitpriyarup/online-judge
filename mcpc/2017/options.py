import itertools

letters = ['c', 'ost', 'mnw', 'diis', 'elos']

fin = open('/usr/share/dict/words')
words = set(w.strip() for w in fin.readlines())
fin.close()

for word in itertools.product(*letters):
    w = ''.join(word)
    print(w, w in words)
    if w in words:
        print(w)
