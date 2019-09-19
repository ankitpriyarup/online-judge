s = input()
safe = ['RUD', 'LUD']
easy = all(c in safe[i % 2] for i, c in enumerate(s))
print('Yes' if easy else 'No')
