import sys

def count(s):
    """Print the number of chars in memory for s"""
    i = 1
    ans = 0
    while i < len(s):
        if s[i] == '\\':
            if s[i + 1] == '\\' or s[i + 1] == '"':
                ans += 1
                i += 2
            elif s[i + 1] == 'x':
                ans += 1
                i += 4
        else:
            ans += 1
            i += 1

    return ans - 1

def escape(s):
    """return the escaped version of this string"""
    ans = ""
    for c in s:
        if c == '\\':
            ans += "\\\\"
        elif c == '"':
            ans += '\\"'
        else:
            ans += c
    return '"' + ans + '"'

def main():
    ans1 = 0
    ans2 = 0
    fin = open('8.in', 'r')
    for line in fin.readlines():
        line = line.strip()
        ans1 += len(line) - count(line)
        ans2 += len(escape(line)) - len(line)
    fin.close()

    print "Part 1", ans1
    print "Part 2", ans2

if __name__ == '__main__':
    main()
