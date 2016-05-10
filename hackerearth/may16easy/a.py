n = int(raw_input())
freq = [0] * 26
for _ in range(n):
    book = raw_input()
    letter = book[0]
    freq[ord(letter) - ord('a')] += 1

ans = 0
for x in freq:
    ans += x / 10
    if x % 10 != 0:
        ans += 1

print(ans)

