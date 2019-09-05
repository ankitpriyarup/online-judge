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

    int n;
    cin >> n;

    vector<vi> a(n, vi(n));

    int k = n / 4;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            int src = 16 * (k * i + j);
            for (int dx = 0; dx < 4; ++dx) {
                for (int dy = 0; dy < 4; ++dy) {
                    a[4 * i + dx][4 * j + dy] = src + 4 * dx + dy;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    /*
    for (int i = 0; i < n; ++i) {
        int c = 0;
        for (int j = 0; j < n; ++j) {
            c ^= a[i][j];
        }
        cout << c << '\n';
    }
 
    for (int j = 0; j < n; ++j) {
        int c = 0;
        for (int i = 0; i < n; ++i) {
            c ^= a[i][j];
        }
        cout << c << '\n';
    }
    */
    return 0;
}
