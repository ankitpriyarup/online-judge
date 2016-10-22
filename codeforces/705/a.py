n = int(input())
words = ["hate", "love"]
p = 0

ans = ""
while n > 0:
    ans += "I {} that ".format(words[p])
    n -= 1
    p = 1 - p

print(ans[:-5] + "it")
