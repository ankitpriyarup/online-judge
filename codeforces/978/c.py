def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    offset = 0
    ptr = 0
    for r in b:
        r -= 1
        while r - offset >= a[ptr]:
            offset += a[ptr]
            ptr += 1
        print(ptr + 1, r - offset + 1)

main()
