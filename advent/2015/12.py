import json

def sum_int(j_obj, part2):
    ans = 0
    if isinstance(j_obj, dict):
        for x in j_obj:
            if part2 and j_obj[x] == "red":
                ans = 0
                break
            ans += sum_int(x, part2)
            ans += sum_int(j_obj[x], part2)
    elif isinstance(j_obj, list):
        for x in j_obj:
            ans += sum_int(x, part2)
    elif isinstance(j_obj, int):
        ans += j_obj

    return ans

def main():
    with open("12.in", "r") as fin:
        json_str = fin.read()
        inp = json.loads(json_str)
        print "Part 1", sum_int(inp, False)
        print "Part 2", sum_int(inp, True)

if __name__ == '__main__':
    main()
