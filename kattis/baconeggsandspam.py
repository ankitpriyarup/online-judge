while True:
    n = int(input())
    if n == 0:
        break
    foods = {}
    for _ in range(n):
        s = input().split()
        person = s[0]
        for food in s[1:]:
            if food not in foods:
                foods[food] = []
            foods[food].append(person)

    foods = list(foods.items())
    foods.sort()
    for food, people in foods:
        people.sort()
        print(food, ' '.join(people))

    print()
