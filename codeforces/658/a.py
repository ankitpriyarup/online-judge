n, c = map(int, input().split())
p = list(map(int, input().split()))
t = list(map(int, input().split()))

lim_score = 0
lim_penalty = 0
for i in range(n):
    lim_penalty += t[i]
    lim_score += max(0, p[i] - lim_penalty * c)

rad_score = 0
rad_penalty = 0
for i in range(n - 1, -1, -1):
    rad_penalty += t[i]
    rad_score += max(0, p[i] - rad_penalty * c)

if lim_score == rad_score:
    print("Tie")
elif lim_score > rad_score:
    print("Limak")
else:
    print("Radewoosh")
