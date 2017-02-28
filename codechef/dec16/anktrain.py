berth = ['LB', 'MB', 'UB', 'LB', 'MB', 'UB', 'SL', 'SU']
T = int(input())
for _ in range(T):
    n = int(input())
    n -= 1
    group = n // 8
    val = n % 8
    if val < 3:
        partner = val + 3
    elif val < 6:
        partner = val - 3
    else:
        partner = 13 - val

    output = group * 8 + partner
    print(str(output + 1) + berth[partner])
