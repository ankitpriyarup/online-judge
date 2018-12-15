from collections import *
import itertools
import random
import sys

sys.setrecursionlimit(1000000)

def main():
    inp = 894501
     #inp = 51589
    goal = list(int(x) for x in str(inp))
    n = len(goal)

    exp_len = inp + 10
    board = [3, 7]
    pos = [0, 1]
    steps = 0
    while True:
        s = list(int(x) for x in str(board[pos[0]] + board[pos[1]]))
        for c in s:
            board.append(c)
            if board[-n:] == goal:
                print(len(board) - n)
                return

        pos[0] = (pos[0] + board[pos[0]] + 1) % len(board)
        pos[1] = (pos[1] + board[pos[1]] + 1) % len(board)
        steps += 1

    print(''.join(map(str, board[exp_len - 10:])))

main()
