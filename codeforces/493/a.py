from collections import defaultdict

def main():
    home = input()
    away = input()
    num_fouls = int(input())

    players = defaultdict(int)
    banned = set()
    for _ in range(num_fouls):
        minute, team, player, card = input().split()
        team_name = home if team == 'h' else away

        if card == 'y':
            players[(team_name, player)] += 1
        else:
            players[(team_name, player)] = 2

        if (team_name, player) not in banned and players[(team_name, player)] >= 2:
            print(team_name, player, minute)
            banned.add((team_name, player))
        

main()
