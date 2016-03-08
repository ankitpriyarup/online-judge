def main():
    valid = {'children': 3, 'samoyeds': 2, 'akitas': 0, 'vizslas': 0, 'cars': 2, 'perfumes': 1}

    fin = open('16.in', 'r')
    for line in fin.readlines():
        line = line.strip()
        words = line.split()
        num = int(words[1][:-1])
        start = line.index(':')
        features = line[start + 2:].split(',')
        features = [x.strip().split(': ') for x in features]
        features = dict((x[0], int(x[1])) for x in features)

        chance = True
        for feat in features:
            if feat in valid and features[feat] != valid[feat]:
                chance = False

        if 'cats' in features and features['cats'] <= 7:
            chance = False

        if 'trees' in features and features['trees'] <= 3:
            chance = False

        if 'pomeranians' in features and features['pomeranians'] >= 3:
            chance = False

        if 'goldfish' in features and features['goldfish'] >= 5:
            chance = False

        if chance:
            print num

    fin.close()

if __name__ == '__main__':
    main()
