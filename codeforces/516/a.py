n = int(raw_input())
a = raw_input()

digit_count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
commands = [{}, {}, {}, {}, {2: 2, 3: 1}, {}, {5: 1, 3: 1}, {}, {7: 1, 2: 3}, {7: 1, 3: 2, 2: 1}]
for c in a:
    cap = ord(c) - ord('0')
    digit_count[cap] += 1

s = ''
for i in xrange(9, 1, -1):
    if commands[i] == {}:
        s += str(i) * digit_count[i]
    else:
        for key in commands[i]:
            digit_count[key] += digit_count[i] * commands[i][key]

print s
