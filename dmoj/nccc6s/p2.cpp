#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int w(const vi& v) {
    int s = 0;
    int e = v.size();
    --e;

    while (s < e and v[s] == 0)
        ++s;
    while (e > s and v[e] == 0)
        --e;
    if (s == e and v[s] == 0)
        return 0;

    return e - s + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vi> a(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vi bad_row(n, 0);
    vi bad_col(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (a[i][j - 1] > a[i][j]){ 
                bad_row[i] = true;
                break;
            }
        }
    }

    for (int j = 0; j < n; ++j) {
        for (int i = 1; i < n; ++i) {
            if (a[i - 1][j] > a[i][j]){ 
                bad_col[j] = true;
                break;
            }
        }
    }

    cout << max(w(bad_row), w(bad_col)) << '\n';
    return 0;
}
