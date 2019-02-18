s = (input())
t = (input())
vowels = 'aeiou'
ans = len(s) == len(t) and all(((a in vowels) == (b in vowels)) for a, b in zip(s, t))
print('Yes' if ans else 'No')
