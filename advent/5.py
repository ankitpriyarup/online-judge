import sys

def three_vowels(s):
    return len(filter(lambda x: x in "aeiou", s)) >= 3

def double(s):
    l = len(s)
    for i in xrange(1, l):
        if s[i] == s[i - 1]:
            return True
    return False

def no_banned(s):
    for bad in ["ab", "cd", "pq", "xy"]:
        if bad in s:
            return False

    return True

def nice_a(s):
    return three_vowels(s) and double(s) and no_banned(s)

def two_pair(s):
    l = len(s)
    for i in xrange(1, l):
        pair = s[(i - 1):(i + 1)]
        if pair in s[(i + 1):]:
            return True
    return False

def sandwich(s):
    l = len(s)
    for i in xrange(1, l - 1):
        if s[i - 1] == s[i + 1]:
            return True
    return False

def nice_b(s):
    return two_pair(s) and sandwich(s)

def main():
    fin = open('5.in', 'r')
    ans = [0, 0]
    for line in fin.readlines():
        if nice_a(line):
            ans[0] += 1
        if nice_b(line):
            ans[1] += 1

    fin.close()

    print "Part 1", ans[0]
    print "Part 2", ans[1]

if __name__ == '__main__':
    main()
