from collections import deque
import hashlib


def find_triples(s):
    for i in range(2, len(s)):
        if s[i] == s[i - 1] and s[i - 1] == s[i - 2]:
            yield s[i]
            break


def md5(s):
    cur = s
    for _ in range(2017):
        m = hashlib.md5()
        m.update(cur.encode('utf-8'))
        cur = m.hexdigest()

    return cur


def main():
    inp = 'cuanljph'
    # inp = 'abc'
    stream = deque([md5(inp + str(index)) for index in range(1000)])
    index = 0
    found = 0
    while found < 65:
        candidate = stream.popleft()
        new_hash = md5(inp + str(index + 1000))
        stream.append(new_hash)

        for char in find_triples(candidate):
            if any(''.join([char] * 5) in thing for thing in stream):
                found += 1
                print(found, index, stream[0])
                break

        index += 1


main()
