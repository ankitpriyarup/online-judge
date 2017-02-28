def exec(commands, start):
    for command, amount in commands:
        if command == 'ADD':
            start += amount
        elif command == 'SUBTRACT':
            start -= amount
            if start < 0:
                return False
        elif command == 'MULTIPLY':
            start *= amount
        elif command == 'DIVIDE':
            if start % amount != 0:
                return False
            start //= amount

    return True



def main():
    n = int(input())
    commands = [input().split() for _ in range(n)]
    commands = [(x, int(y)) for x, y in commands]

    ans = 0
    for i in range(1, 101):
        if not exec(commands, i):
            ans += 1

    print(ans)

main()
