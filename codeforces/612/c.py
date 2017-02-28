def main():
    s = input()
    open_paren = "<([{"
    close = {']': '[', '>': '<', ')': '(', '}': '{'}

    stack = []
    ans = 0
    imp = False
    for c in s:
        if c in open_paren:
            stack.append(c)
        else:
            if not stack:
                imp = True
                break
            if close[c] != stack[-1]:
                ans += 1

            stack.pop()

    imp = imp or len(stack) != 0

    print("Impossible" if imp else ans)


main()
