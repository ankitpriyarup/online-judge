#x, y, y-x, -x, -y, -y+x (loop)

x, y = map(int, raw_input().split())
n = int(raw_input())
n -= 1
n %= 6
arr = [x, y, y - x, -x, -y, -y+x]
ans = arr[n]
print (ans + 1000000007) % 1000000007
