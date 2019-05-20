f = { 'th': 1 }

f['in'] = f['th'] * 1000
f['ft'] = f['in'] * 12
f['yd'] = f['ft'] * 3
f['ch'] = f['yd'] * 22
f['fur'] = f['ch'] * 10
f['mi'] = f['fur'] * 8
f['lea'] = f['mi'] * 3

f['thou'] = f['th']
f['inch'] = f['in']
f['foot'] = f['ft']
f['yard'] = f['yd']
f['chain'] = f['ch']
f['furlong'] = f['fur']
f['mile'] = f['mi']
f['league'] = f['lea']

a, b, _, c = input().split()
a = int(a)
x = a * f[b]
y = x / f[c]
print('{:.15f}'.format(y))
