x = ['Sunny', 'Cloudy', 'Rainy']
a = input()
for i in range(3):
    if a == x[i]:
        print(x[(i + 1) % 3])
