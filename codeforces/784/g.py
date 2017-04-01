OP = '+-'

def get_target():
    cmd = input()
    nums = []
    ops = []

    buf = []
    for c in cmd:
        if c in OP:
            nums.append(int(''.join(buf)))
            ops.append(c)
            buf = []
        else:
            buf.append(c)

    nums.append(int(''.join(buf)))

    return nums, ops

def solve(nums, ops):
    ans = nums[0]
    nums = nums[1:]
    for i, op in enumerate(ops):
        if op == '-':
            ans -= nums[i]
        else:
            ans += nums[i]

    return ans

def main():
    """
    nums, ops = get_target()
    ans = solve(nums, ops)
    out = list(map(int, str(ans)))
    """
    ans = eval(input())
    out = list(map(int, str(ans)))
    # print(out)
    for i, x in enumerate(out):
        print('+' * (x + 48) + '.>')

main()
