n = int(input())
mishka, chris = 0, 0
for _ in range(n):
    a, b = map(int, input().split())
    if a > b:
        mishka += 1
    elif a < b:
        chris += 1

if mishka > chris:
    print("Mishka")
elif chris > mishka:
    print("Chris")
else:
    print("Friendship is magic!^^")
