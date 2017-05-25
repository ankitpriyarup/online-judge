def main():
    R = int(input())
    for _ in range(R):
        L = int(input())
        s = input()
        s = [x for x in s if x != '.']
        ptr = 0
        valid = len(s) % 2 == 0

        while ptr + 2 <= len(s):
            if s[ptr] != 'H' or s[ptr + 1] != 'T':
                valid = False
            ptr += 2

        print('Valid' if valid else 'Invalid')

main()
