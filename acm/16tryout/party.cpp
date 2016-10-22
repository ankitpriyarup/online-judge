#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long f, xp, yp;
long long x[1003];
long long y[1003];

inline long long bound(long long l, long long r, long long p) {
    if (p >= r) {
        return r;
    } else if (p <= l) {
        return l;
    } else {
        return p;
    }
}

int main() {
    long long T;
    cin >> T;
    while (T-- > 0) {
        cin >> f >> xp >> yp;
        for (long long i = 0; i < f; i++) {
            cin >> x[i] >> y[i];
        }
        x[f] = xp;
        y[f] = yp;
        sort(x, x + f + 1);
        sort(y, y + f + 1);

        if (f % 2 == 1) {
            // 1 2 3 4 5 5
            // can be anywhere between x[f / 2 - 1] and x[f / 2]
            long long lx = x[f / 2];
            long long rx = x[(f / 2) + 1];

            long long ly = y[f / 2];
            long long ry = y[(f / 2) + 1];

            // find closest point between (xp, yp) and this square
            long long ax = bound(lx, rx, xp);
            long long ay = bound(ly, ry, yp);

            cout << ax << ' ' << ay << '\n';
        } else {
            // singular meeting point
            cout << x[f / 2] << ' ' << y[f / 2] << '\n';
        }
    }
    return 0;
}
