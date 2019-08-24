#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

inline int sgn(int x) {
    if (x == 0) return 0;
    return x < 0 ? -1 : 1;
}

pii interp(int x1, int y1, int x2, int y2, int lo, int hi, int v) {
    // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << lo << ' ' << hi << ' ' << v << '\n';
    assert(lo <= v and v <= hi);
    int dx = sgn(x2 - x1);
    int dy = sgn(y2 - y1);

    int cur = lo;
    int x = x1;
    int y = y1;
    while (cur < v) {
        x += dx;
        y += dy;
        cur += 1;
    }

    return {x, y};
}

pii solve(int v) {
    if (v == 1) {
        return {0, 0};
    }

    int ring = 1;
    int x = 0;
    int y = 0;
    while ((2 * ring - 1) * (2 * ring - 1) < v) {
        ring += 1;
        x -= 1;
        y -= 1;
    }
    
    int size = 2 * ring - 1;
    int hi = size * size;
    int lo = size * size - (size - 1);
    if (lo <= v) {
        return interp(x + (size - 1), y, x, y, lo, hi, v);
    }

    hi -= size - 1;
    lo -= size - 1;
    x += size - 1;
    if (lo <= v) {
        return interp(x, y + (size - 1), x, y, lo, hi, v);
    }

    hi -= size - 1;
    lo -= size - 1;
    y += size - 1;
    if (lo <= v) {
        return interp(x - (size - 1), y, x, y, lo, hi, v);
    }

    hi -= size - 1;
    lo -= size - 2;
    x -= size - 1;
    return interp(x, y - (size - 2), x, y, lo, hi, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;
    int x1, y1, x2, y2;

    tie(x1, y1) = solve(a);
    tie(x2, y2) = solve(b);

    // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';

    int dist = abs(x1 - x2) + abs(y1 - y2);

    cout << dist << '\n';
    
    return 0;
}
