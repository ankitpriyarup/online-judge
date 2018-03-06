n = int(input())
s = [input() for _ in range(n)]
cold = any(s[i - 2] == s[i - 1] and s[i - 1] == s[i] and s[i] == 'cold' for i in range(2, n))
print('Winter is coming' if cold else 'Another year of summer')
