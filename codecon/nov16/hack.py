#Problem        : License to Hack
#Language       : Python 3
#Compiled Using : py_compile
#Version        : Python 3.4.3
#Input for your program will be provided from STDIN
#Print out all output from your program to STDOUT

import sys

def fix(w, n):
    first = w[:n]
    second = w[n:]
    return first[::-1] + second

s = input()
n = int(input())
flip = True
out = ''
for end in range(n, len(s) + n, n):
    chunk = s[(end - n):end]
    if flip:
        out += chunk[::-1]
    else:
        out += chunk

    flip = not flip

print(out)
