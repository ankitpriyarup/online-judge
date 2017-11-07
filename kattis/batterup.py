def main():
    input()
    scores = list(map(int, input().split()))
    num = sum(x for x in scores if x != -1)
    denom = sum(1 for x in scores if x != -1)


    print(num / denom)

main()
