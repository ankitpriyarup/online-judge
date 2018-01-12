from collections import *
import itertools
import random
import sys

def main():
    cmds = [int(line.strip()) for line in sys.stdin]
    pos = 0
    steps = 0
    while 0 <= pos < len(cmds):
        jmp = cmds[pos]
        if jmp >= 3:
            cmds[pos] -= 1
        else:
            cmds[pos] += 1

        pos += jmp
        steps +=1
    print(steps)

main()
