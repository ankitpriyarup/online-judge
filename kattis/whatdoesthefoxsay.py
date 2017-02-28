def main():
    words = input().split()

    bad = set()
    line = input()
    while line != 'what does the fox say?':
        bad.add(line.split()[-1])
        line = input()

    good = [c for c in words if c not in bad]

    print(' '.join(good))
    

T = int(input())
for _ in range(T):
    main()
