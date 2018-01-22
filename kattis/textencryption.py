def main():
    while True:
        n = int(input())
        if n == 0:
            break
        s = input()
        s = s.replace(' ', '')
        s = s.upper()
        m = len(s)

        res = [' '] * m
        p = 0

        for start in range(m):
            t = start
            if p >= m:
                break
            while t < m:
                if p >= m:
                    break
                res[t] = s[p]
                p += 1
                t += n

        print(''.join(res))

main()
