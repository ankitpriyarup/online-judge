a, b, c = map(int, input().split())
if c == 0:
    print("YES" if a == b else "NO")
else:
    pos = (b - a) % c == 0
    if pos and b >= a and c > 0:
        print("YES")
    elif pos and b <= a and c < 0:
        print("YES")
    else:
        print("NO")
