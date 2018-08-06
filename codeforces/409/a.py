s1 = input()
s2 = input()

win = {
    '()': '8<',
    '[]': '()',
    '8<': '[]'
}

score = [0, 0]
n = len(s1)
for i in range(0, n, 2):
    a = s1[i:i + 2]
    b = s2[i:i + 2]
    if a == b:
        continue

    if win[a] == b:
        score[0] += 1
    else:
        score[1] += 1

if score[0] == score[1]:
    print('TIE')
elif score[0] > score[1]:
    print('TEAM 1 WINS')
else:
    print('TEAM 2 WINS')

