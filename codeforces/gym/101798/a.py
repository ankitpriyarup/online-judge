def main():
    d, w, m = map(int, input().split())
    if w + m <= d or w > d:
        print('good luck')
    else:
        print('see you next semester')

main()
