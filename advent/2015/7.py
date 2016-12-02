import sys

cache = {}
source = {}

def find(name):
    if name in cache:
        return cache[name]
    if '0' <= name[0] <= '9':
        return int(name)

    command = source[name]
    if len(command) == 1:
        cache[name] = find(command[0])
    elif len(command) == 2:
        if command[0] == "NOT":
            cache[name] = ~find(command[1])
    else:
        op = command[1]
        if op == "AND":
            a_val = find(command[0])
            b_val = find(command[2])
            cache[name] = a_val & b_val
        elif op == "OR":
            a_val = find(command[0])
            b_val = find(command[2])
            cache[name] = a_val | b_val
        elif op == "LSHIFT":
            val = find(command[0])
            shift = int(command[2])
            cache[name] = val << shift
        else:
            val = find(command[0])
            shift = int(command[2])
            cache[name] = val >> shift

    return cache[name]

def main():
    fin = open('7.in', 'r')
    for line in fin.readlines():
        line = line.strip()
        tokens = [x.strip() for x in line.split()]
        command = tokens[:-2]
        wire = tokens[-1]
        source[wire] = command
    fin.close()

    ans1 = find('a')
    source['b'] = [str(ans1)]
    cache.clear()
    print "Part 1", ans1
    print "Part 2", find('a')

if __name__ == '__main__':
    main()
