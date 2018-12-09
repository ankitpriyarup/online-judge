def run(s):
    stk = []
    for c in s:
        popped = False
        if stk:
            bk = stk[-1]
            if (('A' <= bk <= 'Z' and 'a' <= c <= 'z') or ('A' <= c <= 'Z' and 'a' <= bk <= 'z')) and bk.lower() == c.lower():
                stk.pop()
                popped = True
        if not popped:
            stk.append(c)
    return len(stk)

def main():
    s = input().strip()
    ans = 1000000
    for k in range(26):
        up = chr(ord('A') + k)
        lo =  chr(ord('a') + k)
        t = str(s)
        t = t.replace(up, '')
        t = t.replace(lo, '')
        print(t)
        ans = min(ans, run(t))
    print(ans)

main()
