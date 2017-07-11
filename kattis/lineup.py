def main():
    n = int(input())
    names = [input() for _ in range(n)]
    asc = names[:]
    desc = names[:]
    asc.sort()
    desc.sort(reverse=True)
    if names == asc:
        print('INCREASING')
    elif names == desc:
        print('DECREASING')
    else:
        print('NEITHER')

main()
