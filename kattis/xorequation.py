from collections import deque

def brute(pat):
    n = len(pat)
    opts = deque([pat])
    for i in range(n):
        sz = len(opts)
        for _ in range(sz):
            x = opts.popleft()
            if x[i] == '?':
                start = 1 if (i == 0 and n > 1) else 0
                cands = range(start, 10)
                for d in cands:
                    opts.append(x[:i] + str(d) + x[i + 1:])
            else:
                opts.append(x)

    return [int(x) for x in opts]

def can_match(exp, pat):
    return len(exp) == len(pat) and all(b == '?' or a == b for a, b in zip(exp, pat))

ans = 0
words = input().split()[::2]
words.sort(key=lambda s: s.count('?'))
for ba in brute(words[0]):
    for bb in brute(words[1]):
        exp = ba ^ bb
        if can_match(str(exp), words[2]):
            ans += 1
if any(word[0] == '0' and len(word) > 1 for word in words):
    ans = 0
print(ans)
