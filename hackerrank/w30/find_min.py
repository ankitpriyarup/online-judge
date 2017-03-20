#!/bin/python

import sys

def run(x):
    if x == 1:
        return "int"
    else:
        return "min(int, {})".format(run(x - 1))

def main():
    n = int(input())
    print(run(n))

main()
