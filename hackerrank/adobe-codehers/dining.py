MOD = 1000000007

def mult(a, b):
    res = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                res[i][j] += a[i][k] * b[k][j]
                res[i][j] %= MOD

    return res

def fib(n):
    mat = [[0, 1], [1, 1]]
    res = [[1, 0], [0, 1]]

    while n > 0:
        if n % 2 == 1:
            res = mult(res, mat)
        mat = mult(mat, mat)
        n //= 2

    return res[1][1]

precomp = [1, 2, 3, 4, 7, 11]
def main():
    n = int(input())
    mat = [[0, 1], [1, 1]]
    res = [[1, 0], [0, 1]]
    if n < len(precomp):
        print(precomp[n])
    else:
        print(fib(n + 1) - fib(n - 3))

main()
