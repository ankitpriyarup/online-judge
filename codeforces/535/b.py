def solve(n):
    l = len(n)
    ans = (1 << l) - 1

    c = lambda x: '1' if x == '7' else '0'
    s = ''.join([c(x) for x in n])
    return ans + int(s, 2)

def main():
    n = raw_input()
    print solve(n)

main()
