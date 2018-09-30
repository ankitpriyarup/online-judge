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

template <typename T>
struct fenwick {
    int n;
    vector<T> ft;


    fenwick(int n): n(n) {
        ft.resize(n + 1, 0.0);
    }

    T query(int x) {
        T res = 0.0;
        for (; x; x -= (x & -x)) {
            res += ft[x];
        }

        return res;
    }

    T pt_query(int x) {
        return query(x) - query(x - 1);
    }

    void update(int x, T v) {
        for (; x <= n; x += (x & -x)) {
            ft[x] += v;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    fenwick<double> ft(n);
    double x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        ft.update(i, log2(x));
    }

    int q;
    cin >> q;
    int k;
    int idx, l, r;
    double p;
    cout << fixed << setprecision(10);
    while (q-- > 0) {
        cin >> k;
        if (k == 1) {
            cin >> idx >> p;
            double old_v = ft.pt_query(idx);
            ft.update(idx, log2(p) - old_v);
        } else {
            cin >> l >> r;
            double res = ft.query(r) - ft.query(l - 1);
            if (res >= 100) {
                cout << "INFINITE!\n";
            } else {
                cout << exp2(res) << '\n';
            }
        }
    }

    return 0;
}
