import re
from collections import Counter

def get_with_freq(data, n):
    freq = Counter()
    for row in data:
        words = re.split(r'\W+', row)
        for word in words:
            freq[word.lower()] += 1

    ans = []
    for word in freq:
        if word and freq[word] == n:
            ans.append(word)

    return ans

def main():
    newline = False
    while True:
        try:
            n = int(input())

            data = []
            line = input()

            while line != 'EndOfText':
                data.append(line)
                line = input()

            ans = get_with_freq(data, n)
            ans.sort()

            if newline:
                print()

            for word in ans:
                print(word)

            if len(ans) == 0:
                print('There is no such word.')

            newline = True
        except EOFError:
            break

main()
