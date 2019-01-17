import sys

seq = '133221333123111'
for x in seq:
    x = int(x)
    print(x)
    sys.stdout.flush()

    resp = input()
    if resp == 'NO':
        sys.exit(-1)

resp = input()
if resp != 'DONE':
    sys.exit(-1)
