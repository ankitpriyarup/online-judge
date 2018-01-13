n, pos, l, r = map(int, input().split())
has_left = l > 1
has_right = r < n
if not has_left and not has_right:
    print(0)
elif has_left and not has_right:
    print(1 + abs(l - pos))
elif not has_left and has_right:
    print(1 + abs(r - pos))
else:
    a = abs(l - pos) + abs(l - r)
    b = abs(r - pos) + abs(r - l)
    print(2 + min(a, b))
