def main():
    a = [input() for _ in range(2)]
    cols = [ord(a[x][0]) - ord('a') for x in range(2)]
    rows = [int(a[x][1]) for x in range(2)]
    if cols[0] < cols[1]:
        col_moves = 'R' * (cols[1] - cols[0])
    else:
        col_moves = 'L' * (cols[0] - cols[1])

    if rows[0] < rows[1]:
        row_moves = 'U' * (rows[1] - rows[0])
    else:
        row_moves = 'D' * (rows[0] - rows[1])

    a = max(len(col_moves), len(row_moves))
    print(a)
    b = min(len(col_moves), len(row_moves))
    for i in range(a):
        if i < b:
            print(col_moves[i] + row_moves[i])
        elif i < len(col_moves):
            print(col_moves[i])
        else:
            print(row_moves[i])

main()
