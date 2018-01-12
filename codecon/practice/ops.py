import sys

def run(a, op, b):
    if op == '-':
        return a - b
    elif op == '+':
        return a + b
    elif op == '*':
        return a * b
    else:
        return a / b

line = input()
tokens = []
ops = []
last = 0
for i in range(len(line)):
    if line[i] in '+*-/':
        tokens.append(float(line[last:i]))
        ops.append(line[i])
        last = i + 1

tokens.append(float(line[last:]))

for op in '-/+*':
    new_tokens = [tokens[0]]
    new_ops = []

    for i in range(len(ops)):
        if ops[i] == op:
            res = float(run(new_tokens[-1], op, tokens[i + 1]))
            new_tokens[-1] = res
        else:
            new_tokens.append(tokens[i + 1])
            new_ops.append(ops[i])

    tokens, ops = new_tokens, new_ops
    
print(int(new_tokens[0] + 0.5))
