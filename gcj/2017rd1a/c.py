def solve():
    drag_health, drag_atk, knight_health, knight_atk, buff, debuff = map(int, input().split())
    # optimal sequence is 
    # 1. debuffs (and cures)
    # 2. buffs (and cures)
    # 3. attacks (and cures)

def main():
    t = int(input())
    for tt in range(t):
        print('Case #{}: {}'.format(tt + 1, solve()))

main()
