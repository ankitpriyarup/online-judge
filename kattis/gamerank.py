needed = [100] + [5] * 10 + [4] * 5 + [3] * 5 + [2] * 5

def add_star(level, stars):
    if level == 0:
        return 0, 1

    if stars == needed[level]:
        return level - 1, 1
    else:
        return level, stars + 1

def lose_star(level, stars):
    if level > 20:
        return level, stars
    if level == 20:
        return level, max(0, stars - 1)
    else:
        if stars > 0:
            return level, stars - 1
        else:
            return level + 1, needed[level + 1] - 1

def main():
    level = 25
    stars = 0
    s = input()
    streak = 0
    for c in s:
        if level == 0:
            break

        if c == 'W':
            streak += 1
            old_level = level
            level, stars = add_star(level, stars)
            if streak >= 3 and old_level >= 6:
                level, stars = add_star(level, stars)
        else:
            streak = 0
            level, stars = lose_star(level, stars)

    print('Legend' if level == 0 else level)

main()
