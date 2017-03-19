from collections import Counter

def main():
    s = Counter(input())
    best_len = 1003
    best_dig = '0'

    for i in range(1, 10):
        need = s[str(i)] + 1
        if need < best_len:
            best_len = need
            best_dig = str(i)

    if s['0'] + 2 <= best_len:
        print('1' + '0' * (s['0'] + 1))
    else:
        print(best_dig * (s[best_dig] + 1))

main()
