class Spell(object):
    def extract_constant(self, spell_str, token):
        index = spell_str.index(token)

        return spell_str[:index], int(spell_str[index + 1:])

    def __init__(self, spell_str):
        # extract out constant first
        self.constant = 0

        if '+' in spell_str:
            spell_str, self.constant = self.extract_constant(spell_str, '+')
        elif '-' in spell_str:
            spell_str, self.constant = self.extract_constant(spell_str, '-')
            self.constant *= -1

        d_index = spell_str.index('d')
        self.num_rolls = int(spell_str[:d_index])
        self.dice_size = int(spell_str[d_index + 1:])

    def beat(self, target_health):
        max_roll = self.num_rolls * self.dice_size + 1
        probabilities = [0.0] * max_roll
        probabilities[0] = 1.0

        for i in range(1, self.num_rolls + 1):
            new_probabilities = [0.0] * max_roll
            for roll in range(1, self.dice_size + 1):
                for j, probability in enumerate(probabilities):
                    if roll + j < max_roll:
                        new_probabilities[roll + j] += (1.0 / self.dice_size) * probability

            probabilities = new_probabilities

        target_health = max(0, target_health - self.constant)
        if target_health >= max_roll:
            return 0

        return sum(probabilities[target_health:])

    def __repr__(self):
        return '{}d{}{:+d}'.format(self.num_rolls, self.dice_size, self.constant)


def main():
    num_cases = int(input())
    for case_num in range(1, num_cases + 1):
        zombie_health, num_spells = map(int, input().split())
        spells = list(map(Spell, input().split()))

        best_probability = max(spell.beat(zombie_health) for spell in spells)

        print("Case #{0}: {1:.06f}".format(case_num, best_probability))


main()
