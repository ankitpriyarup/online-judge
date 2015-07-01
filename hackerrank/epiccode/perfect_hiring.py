# Enter your code here. Read input from STDIN. Print output to STDOUT
n, p, x = map(int, raw_input().split())
a = map(int, raw_input().split())
arr = [(p - x * i) * e for (i, e) in enumerate(a)]
print arr
