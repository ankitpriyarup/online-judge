#!/bin/python

import sys

x = int(raw_input().strip())
# your code goes here
n = x / 3

if x % 3 == 0:
    print n * n * n
elif x % 3 == 1:
    print (n + 1) * n * n
else:
    print (n + 1) * (n + 1) * n
