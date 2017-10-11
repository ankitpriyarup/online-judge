def main():
    T = int(input())
    for _ in range(T):
        x = int(input())
        ans = (x + 400 - 1) // 400
        print(ans)

main()
