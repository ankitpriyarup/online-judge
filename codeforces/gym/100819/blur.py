def fix(v, max):
    return (v + max) % max

ds = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 0), (0, 1), (1, -1), (1, 0), (1, 1)]

def main():
    w, h, b = map(int, input().split())

    den = 81
    for _ in range(b):
        den *= 9

    image = []
    for _ in range(h):
        row = list(map(int, input().split()))
        row = [x * den for x in row]
        image.append(row)

    for _ in range(b):
        new_image = [[0 for _ in range(w)] for _ in range(h)]

        for r in range(h):
            for c in range(w):
                val = 0
                for dx, dy in ds:
                    val += image[fix(r + dx, h)][fix(c + dy, w)]

                new_image[r][c] = val // 9

        image = new_image

    s = set()
    for row in image:
        for v in row:
            s.add(v)

    print(len(s))

main()
