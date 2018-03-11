#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 100005;
int n, m, q;
int uf[2 * MAXN];
int rank[2 * MAXN];
int find(int x) {
    return uf[x] = x == uf[x] ? x : find(uf[x]);
}

bool same_set(int x, int y) {
    return find(x) == find(y);
}

bool merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr)
        return false;
    uf[xr] = yr;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    string s;
    map<string, int> words;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        words[s] = i;
    }
    for (int i = 0; i < 2 * n; ++i) {
        uf[i] = i;
    }

    int kind;
    string x, y;
    for (int i = 0; i < m; ++i) {
        cin >> kind >> x >> y;
        int a = words[x];
        int b = words[y];
        if (kind == 1) {
            // merge 2 * a and 2 * b, 2 * a + 1, 2 * b + 1
            if (same_set(2 * a, 2 * b + 1) or same_set(2 * a + 1, 2 * b)) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                merge(2 * a, 2 * b);
                merge(2 * a + 1, 2 * b + 1);
            }
        } else {
            if (same_set(2 * a, 2 * b) or same_set(2 * a + 1, 2 * b + 1)) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                merge(2 * a, 2 * b + 1);
                merge(2 * a + 1, 2 * b);
            }
        }
    }

    while (q-- > 0) {
        cin >> x >> y;
        int a = words[x];
        int b = words[y];

        if (same_set(2 * a, 2 * b) or same_set(2 * a + 1, 2 * b + 1)) {
            cout << "1\n";
        } else if (same_set(2 * a, 2 * b + 1) or same_set(2 * a + 1, 2 * b)) {
            cout << "2\n";
        } else {
            cout << "3\n";
        }
    }

    return 0;
}
