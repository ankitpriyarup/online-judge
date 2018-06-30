def parse_date(date):
    return [int(x) for x in date.split('/')]

def check(start, birth, courses):
    if start[0] >= 2010 or birth[0] >= 1991:
        return 'eligible'
    if courses >= 41:
        return 'ineligible'

    return 'coach petitions'

def main():
    name, start, birth, courses = input().split()
    start = parse_date(start)
    birth = parse_date(birth)
    courses = int(courses)

    print(name, check(start, birth, courses))

T = int(input())
for _ in range(T):
    main()
