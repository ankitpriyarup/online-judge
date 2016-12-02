def p1(inp):
    return sum(inp)

def p2(inp):
    floor = 0
    for i, move in enumerate(inp):
        floor += move
        if floor < 0:
            return (i + 1)
            
def main():
    fin = open('1.in', 'r')
    s = fin.readline().strip()
    fin.close()
    parsed = [-1 if x == ')' else 1 for x in s]
    print "Part 1", p1(parsed)
    print "Part 2", p2(parsed)

if __name__ == '__main__':
    main()
