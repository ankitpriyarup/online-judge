T = int(raw_input())

for tc in range(T):
    raw_input()
    digits = raw_input()
    digits = list(reversed(sorted(digits)))
    head, tail = ''.join(digits[:-1]), digits[-1]
    head = int(head)
    tail = int(tail)
    print head + tail
