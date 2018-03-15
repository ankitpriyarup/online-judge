def main():
    s = input()
    v = 1
    ans = 0
    for x in reversed(s.split(',')):
        ans += int(x if x else '0') * v
        v *= 60
    print(ans)

T = int(input())
for _ in range(T):
    main()
