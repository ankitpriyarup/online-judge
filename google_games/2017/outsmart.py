from collections import Counter
import requests

def get(found, key):
    flag = '0' * (128 - len(found) - len(key)) + key + found
    url = 'https://ggpuzzles.appspot.com/disarm?key=' + flag
    data = requests.get(url)
    return int(data.text)

def main():
    found = '2606170835242553433788783'
    while len(found) < 128:
        c = Counter()
        out = []
        for i in range(10):
            v = chr(get(found, str(i)))
            c[v] += 1
            out.append(v)

        for i in range(10):
            if c[out[i]] == 1:
                found = str(i) + found

        print(found)

    print(found)

    return

main()
