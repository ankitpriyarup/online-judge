import sys

def piglatin(word):
    vowels = 'aeiouy'
    if word[0] in vowels:
        return word + 'yay'
    else:
        for i, c in enumerate(word):
            if c in vowels:
                return word[i:] + word[:i] + 'ay'

def main():
    for line in sys.stdin.readlines():
        line = line.strip()
        words = line.split()
        out = [piglatin(word) for word in words]
        print(' '.join(out))

main()
