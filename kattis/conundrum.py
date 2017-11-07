def main():
    s = input()
    t = 'PER'
    ptr = 0
    ans = 0
    for c in s:
        if c != t[ptr]:
            ans += 1
        ptr = (ptr + 1) % 3

    print(ans)

main()
