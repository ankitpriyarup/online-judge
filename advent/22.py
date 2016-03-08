from heapq import heappush, heappop

moves = [ {'cost':  53, 'damage': 4, 'heal': 0, 'shield': 0, 'poison': 0, 'recharge': 0},
          {'cost':  73, 'damage': 2, 'heal': 2, 'shield': 0, 'poison': 0, 'recharge': 0},
          {'cost': 113, 'damage': 0, 'heal': 0, 'shield': 6, 'poison': 0, 'recharge': 0},
          {'cost': 173, 'damage': 0, 'heal': 0, 'shield': 0, 'poison': 6, 'recharge': 0},
          {'cost': 229, 'damage': 0, 'heal': 0, 'shield': 0, 'poison': 0, 'recharge': 5} ]

def run_effects(status):
    new_status = status.copy()
    if new_status['shield'] > 0:
        new_status['armor'] = True
        new_status['shield'] -= 1
    else:
        new_status['armor'] = False

    if new_status['poison'] > 0:
        new_status['ehealth'] -= 3
        new_status['poison'] -= 1

    if new_status['recharge'] > 0:
        new_status['mana'] += 101 
        new_status['recharge'] -= 1

    return new_status

def main():
    boss_dmg = 9
    armor = 7
    start = {'health': 50, 'mana': 500, 'ehealth': 58, 'shield': 0, 'poison': 0, 'recharge': 0, 'armor': False, 'player_turn': True}
    heap = []
    heappush(heap, (0, start))
    hard = True

    while len(heap) > 0:
        spent, status = heappop(heap)
        if hard and status['player_turn']:
            status['health'] -= 1

        status = run_effects(status)

        if status['health'] <= 0 or status['mana'] <= 0:
            continue

        if status['ehealth'] <= 0:
            print spent
            break

        if status['player_turn']:
            for move in moves:
                new_status = status.copy()

                new_status['mana'] -= move['cost']
                if new_status['mana'] < 0:
                    continue

                new_status['health'] += move['heal']
                new_status['ehealth'] -= move['damage']
                if (new_status['shield'] > 0 and move['shield'] > 0) or (new_status['poison'] > 0 and move['poison'] > 0) or (new_status['recharge'] > 0 and move['recharge'] > 0):
                    continue

                new_status['shield'] += move['shield']
                new_status['poison'] += move['poison']
                new_status['recharge'] += move['recharge']
                new_status['player_turn'] = not new_status['player_turn']
                heappush(heap, (spent + move['cost'], new_status))
        else:
            new_status = status.copy()
            new_status['health'] -= boss_dmg - armor if new_status['armor'] else boss_dmg
            new_status['player_turn'] = not new_status['player_turn']
            heappush(heap, (spent, new_status))

if __name__ == '__main__':
    main()
