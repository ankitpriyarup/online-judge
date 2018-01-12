def read_text():
    out = []
    while (not out) or out[-1][-1] != '|':
        out.append(input())

    return ' '.join(out)

def solve():
    d = int(input())
    f = int(input())
    authors = list(map(lambda x: x.strip(), input()[:-1].split(',')))
    print(authors)
    for _ in range(d):
        s = read_text()

def main():
    T = int(input())
    for case in range(1, T + 1):
        print('Case', case)
        solve()
    

main()
