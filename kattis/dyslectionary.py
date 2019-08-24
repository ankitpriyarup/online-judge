import sys

first = True
def solve(words):
    global first
    max_len = max(len(s) for s in words)
    words.sort(key=lambda word: ''.join(reversed(word)))
    if not first:
        print()
    for word in words:
        padding = max_len - len(word)
        print((' ' * padding) + word)
    first = False

words = []
for line in sys.stdin:
    line = line.strip()
    if line == '':
        solve(words)
        words = []
    else:
        words.append(line)

if words:
    solve(words)
