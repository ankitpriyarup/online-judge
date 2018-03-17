def main():
    n = int(input())
    lo = float('-inf')
    hi = float('inf')
    for _ in range(n):
        a, b = map(int, input().split())
        lo = max(lo, a)
        hi = min(hi, b)
    if lo <= hi:
        print('gunilla has a point')
    else:
        print('edward is right')

main()
