#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int h;
    cin >> h;
    ++h;
    vi a(h);

    int n = 0;
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
        n += a[i];
    }

    vi left_par(n), right_par(n);
    left_par[0] = right_par[0] = -1;
    int s = 1;
    for (int i = 1; i < h; ++i) {
        int old_s = s - a[i - 1];
        int e = s + a[i];

        left_par[s] = old_s;
        right_par[s] = old_s;

        for (int j = s + 1; j < e; ++j) {
            left_par[j] = old_s;
            right_par[j] = s - 1;
        }

        s = e;
    }

    if (left_par == right_par) {
        cout << "perfect\n";
    } else {
        cout << "ambiguous\n";
        for (int i = 0; i < n; ++i) {
            cout << left_par[i] + 1 << ' ';
        }
        cout << '\n';
        for (int i = 0; i < n; ++i) {
            cout << right_par[i] + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}
