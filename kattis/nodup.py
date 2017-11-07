import sys

def main():
    words = input().strip().split()

    if len(set(words)) == len(words):
        print('yes')
    else:
        print('no')

main()
