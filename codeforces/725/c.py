from collections import Counter

def display(r1, r2):
    if len(r1) > 13:
        r1, r2 = r1[:13], r2 + (r1[13:])[::-1]
    elif len(r2) > 13:
        r1, r2 = r1 + (r2[13:])[::-1], r2[:13]

    print(r1)
    print(r2)

def main():
    s = input()
    counter = Counter(s)
    double = None
    for c in s:
        if counter[c] == 2:
            double = c

    a = s.index(double)
    b = s.index(double, a + 1)
    if a + 1 == b:
        print("Impossible")
        return

    grid = [['0' for _ in range(13)] for _ in range(2)]
    first = s[:a]
    second = s[b + 1:]
    middle_chunk = s[a + 1:b]
    mid_len = len(middle_chunk)

    if mid_len == 1:
        display(double + first[::-1], middle_chunk + second)
        return
    else:
        # otherwise we have at least 4 edges to consider
        cols = mid_len // 2
        r1 = (middle_chunk[:cols])[::-1] + double + first[::-1]
        r2 = middle_chunk[cols:] + second
        display(r1, r2)

main()
