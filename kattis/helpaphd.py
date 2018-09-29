T = int(input())
for _ in range(T):
    s = input()
    if s == 'P=NP':
        print('skipped')
    else:
        print(eval(s))
