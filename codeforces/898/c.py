from collections import defaultdict

def fix(nums):
    nums.sort(key=len, reverse=True)
    seen = set()
    fin = []
    for x in nums:
        if x in seen:
            continue
        fin.append(x)
        for i in range(len(x)):
            seen.add(x[i:])

    return fin


def main():
    n = int(input())
    by_name = defaultdict(list)
    for _ in range(n):
        line = input().split()
        name = line[0]
        nums = line[2:]
        by_name[name] += nums

    print(len(by_name))
    for name, nums in by_name.items():
        fixed = fix(nums)
        print(name, len(fixed), ' '.join(str(x) for x in fixed))


main()
